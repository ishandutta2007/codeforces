#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const ll MAX = 1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

int n,a,cnt,x[MAX];
vector<pii> ans;

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>a;
	rep(i,1,n)cin>>x[i];
	rep(i,2,n)if(x[i]!=x[1]+a*(i-1))ans.pb({i,x[i]-x[1]-a*(i-1)});
	rep(i,2,n){
		if(x[i]+a*(1-i)<=0)continue;
		cnt = 0;
		rep(j,1,n)if(x[j]!=x[i]+a*(j-i))cnt++;
		if(cnt<ans.size()){
			ans.clear();
			rep(j,1,n)if(x[j]!=x[i]+a*(j-i))ans.pb({j,x[j]-x[i]-a*(j-i)});
		}
	}
	cout<<ans.size()<<endl;
	for(auto i:ans){
		if(i.se>0)cout<<"- ";
		else cout<<"+ ";
		cout<<i.fi<<" "<<abs(i.se)<<endl;
	}
    return 0;
}