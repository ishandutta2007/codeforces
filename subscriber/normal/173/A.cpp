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

int n,n1,n2,k,x,a1,a2,g[1111111];
string a,b;
char s1[1111111],s2[1111111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> a >> b;
	n1=a.size();
	n2=b.size();
	for (int i=0;i<n1*n2;i++){
		s1[i]=a[i%n1];
		s2[i]=b[i%n2];
		if (s1[i]=='S'&&s2[i]=='P')g[i]=1;
		if (s1[i]=='P'&&s2[i]=='R')g[i]=1;
		if (s1[i]=='R'&&s2[i]=='S')g[i]=1;
		if (s1[i]=='P'&&s2[i]=='S')g[i]=-1;
		if (s1[i]=='R'&&s2[i]=='P')g[i]=-1;
		if (s1[i]=='S'&&s2[i]=='R')g[i]=-1;
	}
	k=n1*n2;
	for (int i=0;i<k;i++){
		x=n/k+(n%k>i);
		if (g[i]==1)a2+=x;
		if (g[i]==-1)a1+=x;
	}
	cout << a1 << " " << a2 << endl;
	return 0;
}