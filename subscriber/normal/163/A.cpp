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

int x,ans,g[5005][5005],s[5005][5005];
string a,b;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> a >> b;
	for (int i=1;i<=a.size();i++)for (int j=1;j<=b.size();j++)if (a[i-1]==b[j-1]){
		g[i][j]=(s[i-1][j-1]+1)%M;
		s[i][j]=(s[i][j-1]+g[i][j])%M;
	}else s[i][j]=s[i][j-1];
	for (int i=1;i<=a.size();i++)for (int j=1;j<=b.size();j++)ans=(ans+g[i][j])%M;
	CC(ans);
	return 0;
}