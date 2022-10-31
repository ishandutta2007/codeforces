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
ll mod=998244353;
ll arr[1010101];
ll lchk[310101];
ll vis[10101010];
ll pre[303030];
ll prehol[303030];
ll prejak[303030];

ll n,m;
string s;
vector<pii> ans;
vector<ll> v;

bool sf(ll a,ll b){
    if(arr[a]%2&&arr[b]%2==0) return 0;
    if(arr[a]%2==0&&arr[b]%2) return 1;
    return a<b;
}

vector <ll> pri;
ll com[1010100];

void sieve (ll n) {
    for (ll i = 2; i < n; ++i) {
        if (com[i]==0) pri.pb(i);
        for(auto k:pri){
            if(i*k>=n) break;
            com[i*k]=1;
            if(i%k==0) break;

        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;

    sieve(1010);
    ll i,j,k,l;
    ll chk=0,cnt=0,val;
    ll a=0,b=0,c=0,d=0,x=0;
    ll e,f,g,h;
    ll cnta=0,cntb=0;
    ll lawin=0;
    ll ans=1;

    cin>>n>>m;
    for(auto p:pri){
    	a=n;
    	chk=1;
    	while((a%p)==0){
    		ll val=1;
    		if(p==2){
	    		k=a/p;
	    		cout<<"?"<<' '<<a-k<<' '<<m<<' '<<1<<' '<<1<<' '<<k+1<<' '<<1<<endl;
	    		cin>>x;
	    		
	    		if(x==1) chk++;
	    		else break;
	    	}
	    	else{
	    		ll hp=p/2;
	    		k=a/p;
	    		cout<<"?"<<' '<<hp*k<<' '<<m<<' '<<1<<' '<<1<<' '<<k*(hp+1)+1<<' '<<1<<endl;
	    		cin>>x;
	    		val*=x;
	    		cout<<"?"<<' '<<hp*k<<' '<<m<<' '<<k+1<<' '<<1<<' '<<k*(hp+1)+1<<' '<<1<<endl;
	    		cin>>x;
	    		val*=x;
	    		if(val==1) chk++;
	    		else break;
	    	}
	    	a/=p;
    	}
    	ans*=chk;
    }
    for(auto p:pri){
    	a=m;
    	chk=1;
    	while(a%p==0){
    		ll val=1;
    		if(p==2){
	    		k=a/p;
	    		cout<<"?"<<' '<<n<<' '<<a-k<<' '<<1<<' '<<1<<' '<<1<<' '<<k+1<<endl;
	    		cin>>x;
	    		if(x==1) chk++;
	    		else break;
	    	}
	    	else{
	    		ll hp=p/2;
	    		k=a/p;
	    		cout<<"?"<<' '<<n<<' '<<hp*k<<' '<<1<<' '<<1<<' '<<1<<' '<<k*(hp+1)+1<<endl;
	    		cin>>x;
	    		val*=x;
	    		cout<<"?"<<' '<<n<<' '<<hp*k<<' '<<1<<' '<<k+1<<' '<<1<<' '<<k*(hp+1)+1<<endl;
	    		cin>>x;
	    		val*=x;
	    		if(val==1) chk++;
	    		else break;
	    	}
	    	a/=p;
    	}
    	ans*=chk;
    }
    cout<<"! "<<ans<<endl;
}