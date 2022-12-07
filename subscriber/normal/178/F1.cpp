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
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,k,f[111][111],ans=0;
string s[111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k;
	for (int i=0;i<n;i++)cin >> s[i];
	sort(s,s+n);
	for (int i=0;i<n;i++)for (int j=0;j<n;j++){
		f[i][j]=0;
		while (f[i][j]<s[i].size()&&f[i][j]<s[j].size()&&s[i][f[i][j]]==s[j][f[i][j]])f[i][j]++;
	}
	for (int o=0;o<pw(n);o++){
		int t=0,s=0;
		for (int i=0;i<n;i++)if (o&pw(i))t++;
		if (t!=k)continue;
		for (int i=0;i<n;i++)if (o&pw(i))for (int j=0;j<i;j++)if (o&pw(j))s+=f[i][j];
		ans=max(ans,s);
	}
	CC(ans);
	return 0;
}