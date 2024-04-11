#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;

#define ff first
#define ss second
#define eb emplace_back
#define ep emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) lower_bound(all(v), x) - v.begin()
//cout<<fixed;
//cout.precision(12);

struct poi{
    ll val,xx,yy;
};

vector<ll> x;
ll n,m;
ll mod=998244353;
string s;
string t;
ll arr[1010101];
vector<ll> v[1010101];
vector<ll> chd[1010101];
ll pre[1010101];
ll suf[1010101];
ll brr[1010101];
ll dep[1010101];
ll vis[1010101];
ll flw[1010101];
ll dp[1010101];
ll par[1010101];

vector<ll> cn;
vector<ll> cna;
vector<ll> cnb;
vector<ll> cnc;

void sol(){
	ll i;
    string s1,s2,s3,s4;
    if(cn.size()==1){
        ll l=cn[0];
        cout<<"! "<<l<<endl;
        cin>>s1;
        return ;
    }
    if(cn.size()==2){
        ll l=cn[0];
        ll r=cn[1];
        cout<<"! "<<l<<endl;
        cin>>s1;
        if(s1==":("){
            cout<<"! "<<r<<endl;
            cin>>s1;
        }
        return;
    }

    ll sz=cn.size();
    for(i=0;i<sz;i++){
        if(i%3==0){
            cna.pb(cn[i]);
        }
        if(i%3==1){
            cnb.pb(cn[i]);
        }
        if(i%3==2){
            cnc.pb(cn[i]);
        }
    }
    cn.clear();

    cout<<"? "<<cna.size();
    for(auto k:cna)
        cout<<" "<<k;
    cout<<endl;
    cin>>s1;

    if(s1=="NO"){
    	cout<<"? "<<cna.size();
	    for(auto k:cna)
	        cout<<" "<<k;
	    cout<<endl;
	    cin>>s1;

	    if(s1=="NO"){
	    	for(auto k:cnb)
	    		cn.pb(k);
	    	for(auto k:cnc)
	    		cn.pb(k);
	    	cna.clear();
	    	cnb.clear();
	    	cnc.clear();
	    	sol();
	    	return ;
	    }
	    else{
	    	cout<<"? "<<cnb.size();
		    for(auto k:cnb)
		        cout<<" "<<k;
		    cout<<endl;
		    cin>>s1;

		    if(s1=="YES"){
		    	for(auto k:cnb)
		    		cn.pb(k);
		    	for(auto k:cna)
		    		cn.pb(k);
		    	cna.clear();
		    	cnb.clear();
		    	cnc.clear();
	    	sol();
		    	return ;
		    }
		    else{
	    		for(auto k:cna)
	    			cn.pb(k);
				for(auto k:cnc)
		    		cn.pb(k);
		    	cna.clear();
		    	cnb.clear();
		    	cnc.clear();
	    	sol();
		    	return ;
		    }
	    }
    }
    else{
    	cout<<"? "<<cnb.size();
	    for(auto k:cnb)
	        cout<<" "<<k;
	    cout<<endl;
	    cin>>s1;

	    if(s1=="YES"){
	    	for(auto k:cnb)
	    		cn.pb(k);
	    	for(auto k:cna)
	    		cn.pb(k);
	    	cna.clear();
	    	cnb.clear();
	    	cnc.clear();
	    	sol();
	    	return ;
	    }
	    else{
	    	for(auto k:cna)
	    		cn.pb(k);
			for(auto k:cnc)
	    		cn.pb(k);
	    	cna.clear();
	    	cnb.clear();
	    	cnc.clear();
	    	sol();
	    	return ;
	    }
    }


}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t;
    cin>>n;
    for(ll i=1;i<=n;i++)
        cn.pb(i);
    sol();
    return 0;
}