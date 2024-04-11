#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

int n,x,y,mx = 100000,tmp,ans,z[MAX],gd,cnt[MAX],vis[MAX],mv[MAX],jln;
queue<pii> q;

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(a,1,n){
    	cin>>z[a];
    	y = z[a];
    	vis[y] = a;
    	cnt[y]++;
		q.push({y,0});
		while(!q.empty()){
			x = q.front().fi, jln = q.front().se; q.pop();
			if(vis[x>>1]!=a){
				mv[x>>1]+=jln+1;
				cnt[x>>1]++;
				vis[x>>1] = a;
				q.push({x>>1,jln+1});
			}
			if((x<<1)<=mx&&vis[x<<1]!=a){
				mv[x<<1]+=jln+1;
				cnt[x<<1]++;
				vis[x<<1] = a;
				q.push({x<<1,jln+1});
			}
		}
	}
	ans = 1e9;
	rep(i,1,100000){
		if(cnt[i]!=n)continue;
//		cout<<i<<" = "<<mv[i]<<endl;
		ans = min(mv[i],ans);
	}
	cout<<ans<<endl;
    return 0;
}