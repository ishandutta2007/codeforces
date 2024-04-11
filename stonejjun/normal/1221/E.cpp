#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
//cout<<fixed;
//cout.precision(12);
ll mod=1000000007;
ll qwe[1010101];
ll arr[1010101];
ll brr[1010101];
ll n;
string s;
vector<pii> ans;
vector<ll> v;
bool sf(ll a,ll b){
    return a>b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;
    ll i,j,k,l,m;
    ll chk=0,cnt=0,val;
    ll a=0,b=0,c=0,d=0;
    ll e,f,g,h;
    ll cnta=0,cntb=0;
    ll lawin=0;
    
    cin>>t;
    while(t--){
        ll chk=0,cnt=0,val;
        ll a=0,b=0,c=0,d=0;
        ll e,f,g,h;
        ll cnta=0,cntb=0,ans=0;
        ll lawin=0;
        ll mov=0;
        v.clear();

        cin>>a>>b>>s;
        n=s.size();

        //cout<<n<<'\n';
        for(i=0;i<n;i++){
            if(s[i]=='.') cnt++;
            else{
                if(cnt>=b) v.pb(cnt);
                cnt=0;
            }
        }

        if(cnt>=b) v.pb(cnt);
        cnt=0;

        if(v.size()==0){
            cout<<"NO"<<'\n';
            continue;
        }

        sort(v.begin(), v.end(),sf);
        if(v[v.size()-1]<a){
            cout<<"NO"<<'\n';
            continue;
        }
        if(v.size()>=2&&v[1]>=2*b){
        	cout<<"NO"<<'\n';
        	continue;
        }
        if(v[0]>a+b+b+b+b-2){
        	cout<<"NO"<<'\n';
        	continue;
        }
        for(auto k:v){
        	ll v1=0,v2=4;
        	if(k>=a) v1++;
        	if(k>=2*a) v1++;
        	if(k>=3*a) v1++;
        	if(k<=a+2*b-2) v2--;
        	if(k<=a+3*b-2) v2--;
        	if(k<=a+4*b-2) v2--;
        	if(v2>v1) chk=1;
        	if(v1!=v2) lawin=1;
        	else cnt+=v1;
        }
        if(chk){
        	cout<<"NO"<<'\n';
        }
        else if(lawin){
        	cout<<"YES"<<'\n';
        }
        else if(cnt%2){
        	cout<<"YES"<<'\n';
        }
        else{
        	cout<<"NO"<<'\n';
        }


   }
}