#include <bits/stdc++.h>
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
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
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,p,q,a,b,x[MAX],y[MAX],ans,le,ri,mid;
bool st,keluar;

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>p>>q>>a>>b;
    rep(i,1,n)cin>>x[i];
    if(p>q){
    	swap(p,q); swap(a,b);
    	reverse(x+1,x+1+n);
	}
	rep(i,1,n)y[i] = y[i-1]+x[i];
   	le = 2, ri = n, ans = x[1]*p, st = 1;
   	while(le<=ri){
   		if((ri+le)&1)mid = (le+ri)/2;
   		else {
   			if(st)mid = (le+ri)/2-1;
		}
   		if(st){
   			if((y[ri]-y[mid])*q>(ri-le+1)*a+(y[ri]-y[mid])*p)ans+=x[le++]*p+a;
   			else ans+=x[ri--]*q, st = 0;
		}
		else {
			ans+=x[le++]*p, st = 1;
		}
	}
	cout<<ans<<endl;
    return 0;
}