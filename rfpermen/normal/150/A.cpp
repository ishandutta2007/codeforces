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

ll n,sqr,cnt,ans;
vector<int> v; 

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    sqr = sqrt(n);
    rep(i,2,sqr){
    	if(n%i==0){
    		cnt++;
    		v.pb(i);
    		if(n/i!=i)v.pb(n/i),cnt++;
		}
	}
    if(!cnt)return cout<<"1\n0",0;
    sort(v.begin(),v.end());
    for(auto j:v){
    	sqr = sqrt(j);
    	cnt = 0;
    	rep(i,2,sqr){
	    	if(j%i==0){
	    		cnt++;
	    		v.pb(i);
	    		if(j/i!=i)cnt++;
			}
		}
//		cout<<j<<" "<<cnt<<endl;
		if(cnt==1 || cnt==2)return cout<<"1\n"<<j,0;
	}
	cout<<2;
    return 0;
}