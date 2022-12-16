// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const int maxn=1e6+10;

#pragma GCC Optimize("Ofast")
#pragma GCC Optimize("O1")
#pragma GCC Optimize("O2")
#pragma GCC Optimize("O3")
#pragma GCC Optimize("O4")
#pragma GCC Optimize("O5")

int bef[maxn];
bool is[maxn];

int main(){
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	
	is[n]=1;
	REP(i,m){
		int x;scanf("%d",&x);
		is[x]=1;
	}
	if(is[0]){
		cout<<-1;
		return 0;
	}
	FOR(i,1,n)
		bef[i]=(is[i]?bef[i-1]:i);
	
	ll ans=inf;
	FOR(i,1,k){
		int x;scanf("%d",&x);
		int bf=0,num=0;
		while(bf<n){
			if((bef[bf]+i)<=bf) goto hell;
			num++;
			bf=bef[bf]+i;
		}
		ans=min(ans,ll(ll(num)*ll(x)));
		hell:;
	}
	cout<<(ans==inf?-1:ans);
}