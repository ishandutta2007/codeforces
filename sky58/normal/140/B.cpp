#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int fav[310][310];
int fa[310];
bool aru[310];
int main()
{
	int i,j,n;
	cin>>n;
	rep(i,n) rep(j,n){
		scanf("%d",&fav[i][j]);
	}
	rep(i,n) scanf("%d",&fa[i]);
	rep(i,n){
		memset(aru,false,sizeof(aru));
		int ma=500;
		rep(j,n){
			if(fa[j]==i+1) continue;
			if(ma>fa[j]){
				aru[fa[j]]=true;ma=fa[j];
			}
		}
		rep(j,n){
			if(aru[fav[i][j]]) break;
		}
		cout<<fav[i][j];
		if(i<n-1) cout<<" ";else cout<<endl;
	}
	return 0;
}