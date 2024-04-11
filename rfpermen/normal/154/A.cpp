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
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int k,a,b,nw,ans;
string s,c;
char x,y;
int m[128];

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    cin>>k;
    rep(i,1,k){
    	cin>>x>>y;
    	m[x] = i*2, m[y] = i*2+1;
	}
	for(auto i:s){
		if(nw!=m[i]/2){
			ans+=min(a,b);
			a = b = 0;
			nw = m[i]/2;
		}
		if(!m[i])continue;
		if(m[i]&1)a++;
		else b++;
	}
	cout<<ans+min(a,b);
    return 0;
}