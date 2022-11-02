#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin>>tt;
    while(tt--){
    	ll i,j,k,l,a,b,c;
    	cin>>n>>m;
    	cin>>s>>t;
    	ll fl=n-1;
    	ll mang=0;
    	for(i=m-1;i>0;i--){
    		if(s[fl]!=t[i]){
    			mang=1;
    			break;
    		}
    		fl--;
    	}
    	if(mang){
    		cout<<"NO"<<'\n';
    		continue;
    	}

    	mang=1;
    	for(i=fl;i>=0;i--){
    		if(s[i]==t[0]) mang=0;
    	}


    	if(mang){
    		cout<<"NO"<<'\n';
    		continue;
    	}
    	else{
    		cout<<"YES"<<'\n';
    	}
    }
}