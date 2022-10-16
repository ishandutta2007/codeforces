#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define w fi
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define pdi pair<double,int>
#define endl "\n"
const ll MAX=1e4+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int cnt,x,sz;
string s;
vector<int> v;

int main(){
	cout<<fixed<<setprecision(5);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for(auto i:s){
    	if(i=='1')x++;
    	else if(i=='0')cnt++;
    	else {
    		v.pb(cnt);
    		cnt=0;
		}
	}
	
	sz = v.size(); sz--;
	if(v.empty()){
		rep(i,1,cnt)cout<<"0";
		rep(i,1,x)cout<<"1";
		return 0;
	}
	else {
		rep(i,1,v[0])cout<<"0";
		rep(i,1,x)cout<<"1";
		cout<<"2";
	}
	rep(i,1,sz){
		rep(j,1,v[i])cout<<"0";
		cout<<"2";
	}
	rep(i,1,cnt)cout<<"0";
    return 0;
}