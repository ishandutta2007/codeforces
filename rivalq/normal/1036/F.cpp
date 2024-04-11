#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int N = 100;
int lp[N+1];
int pr[N];int t=0;
const int inf=1e18;

int xymodp(int x,int y){
    int a=1;
    while(y){
        if(y&1)a=(a*x);
        x=(x*x);
        y/=2;
    }
    return a;
}


void sieve(){
    for (int i=2; i<N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[t++]=i;
            }
        for (int j=0; j<t && pr[j]<=lp[i] && i*pr[j]<N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
ll sq(long double k){
   ll ans=sqrt(k);
   while(ans*ans<k)ans++;
   while(ans*ans>k)ans--;
   return ans;
}   

set<int>st;
vector<int>v;
void func(){
	for(int i=3;i<=60;i++){
		if(lp[i]==i){
			long double k=(long double)18/i;
			long double maxx=pow(10,k);
			for(int j=2;j<=maxx;j++){
				int val=xymodp(j,i);
				int z=sq(val);
				if(val==z*z)continue;
				st.insert(val);				
			}
		}
	}
}


int solve(){
 	int n;cin>>n;
 	int ans=sq(n);
 	if(v[0]<=n){
 		int j=upper_bound(all(v),n)-v.begin();
 		ans+=j;
 	}
 	cout<<n-ans<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();
    func();
    for(auto i:st){
    	v.pb(i);
    }
    //for(int i=0;i<10;i++)cout<<v[i]<<" ";cout<<endl;
    #ifdef NCR
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}