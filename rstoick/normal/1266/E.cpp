#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
 
const ll mod = 1000000007;
 
int n,q;
map<P,int>S;
int a[200005];
int cnt[200005];
ll ans;
 
int main(){
	scanf("%d",&n); repn(i,n){ scanf("%d",&a[i]); ans += a[i]; }
	scanf("%d",&q);
	rep(i,q){
		int s,t,u; scanf("%d%d%d",&s,&t,&u);
		if(S.find(P(s,t)) != S.end()){
			int A = S[mp(s,t)];
			cnt[A]--;
			if(cnt[A] < a[A]) ans++;
			
			if(!u) S.erase(S.find(P(s,t)));
			else{
				S[mp(s,t)] = u;
				cnt[u]++;
				if(cnt[u] <= a[u]) ans--;
			}
		}
		else{
			S[mp(s,t)] = u;
			cnt[u]++;
			if(cnt[u] <= a[u]) ans--;
		}
		printf("%lld\n",ans);
	}
}