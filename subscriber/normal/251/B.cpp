#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n,k,f[444][444];
vector<int>p[444];
vector<int>q,s;

vector<int>gg(vector<int> a){
	vector<int>b(n);
	for (int i=0;i<n;i++)b[i]=a[q[i]];
	return b;
}

vector<int>pp(vector<int> a){
	vector<int>b(n);
	for (int i=0;i<n;i++)b[q[i]]=a[i];
	return b;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k;
	q.resize(n);
	s.resize(n);
	for (int i=0;i<n;i++)cin >> q[i],q[i]--;
	for (int i=0;i<n;i++)cin >> s[i],s[i]--;
	p[k].resize(n);
	for (int i=0;i<n;i++)p[k][i]=i;
	for (int i=k+1;i<=k+k;i++)p[i]=gg(p[i-1]);
	for (int i=k-1;i>=0;i--)p[i]=pp(p[i+1]);
	if (p[k]!=s)f[0][k]=1;
	for (int i=0;i<k;i++)for (int j=1;j<k+k;j++)if (f[i][j]){
		if (p[j+1]!=s)f[i+1][j+1]=1;
		if (p[j-1]!=s)f[i+1][j-1]=1;
		if (i==k-1&&(p[j+1]==s||p[j-1]==s)){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}