#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define pll pair<int,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int a,b,cek;
vector<pii> v[1005];

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,1000)rep(j,1,1000){
    	cek = sqrt(i*i+j*j);
    	if(cek*cek==i*i+j*j && cek<1001)v[cek].pb({i,j});
	}
	cin>>a>>b;
	if(v[a].empty() || v[b].empty())return cout<<"NO",0;
	for(auto i:v[a]){
		for(auto j:v[b]){
			cek = (i.fi+j.se)*(i.fi+j.se) + (i.se-j.fi)*(i.se-j.fi);
			if(cek==a*a+b*b && i.se!=j.fi)return cout<<"YES\n0 0\n"<<i.fi<<" "<<i.se<<"\n"<<-j.se<<" "<<j.fi,0;
		}
	}
	cout<<"NO";
    return 0;
}