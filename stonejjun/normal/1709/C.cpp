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
string s;
ll mod=998244353;
ll arr[1010101];
ll pre[1010101];
ll suf[1010101];

vector<ll> v[1010101];
ll chk[1010101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
   		ll i,j,k,a=0,b=0,c=0,d,e,f;
   		cin>>s;
   		n=s.size();

   		for(i=1;i<=n;i++){
   			if(s[i-1]=='('){
   				arr[i]=0;
   				a++;
   			}
   			if(s[i-1]==')'){
   				arr[i]=1;
   				b++;
   			}

   			if(s[i-1]=='?'){
   				arr[i]=2;
   				c++;
   			}
   		}

   		ll fl=1;
   		d=n/2-a;
   		e=n/2-b;
   		if(d<=0||e<=0){
   			cout<<"YES"<<'\n';
   			continue;
   		}
   		for(i=1;i<=n;i++){
   			if(arr[i]==2){
   				if(d==1&&fl==1){
   					fl=-1;
   					e--;
   					arr[i]=1;
   				}
   				else if(d){
   					d--;
   					arr[i]=0;
   				}
   				else if(fl==-1){
   					fl=0;
   					d--;
   					arr[i]=0;
   				}
   				else{
   					arr[i]=1;
   				}
   			}
   		}

   		ll val=0;
   		ll ans=0;
   		for(i=1;i<=n;i++){
   			if(arr[i]==1) val--;
   			else val++;
   			ans=min(ans,val);
   		}
   		if(ans<0){
   			cout<<"YES"<<'\n';
   		}
   		else cout<<"NO"<<'\n';
   	}
}