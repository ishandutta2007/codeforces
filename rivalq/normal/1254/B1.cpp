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


const int N = 1000050;
const int M=2e7;
int lp[N+1];
int pr[N];int t=0;
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


int solve(){
 	int n;cin>>n;
 	vector<int>a(n+1);
 	int s=0;
 	rep(i,1,n+1){
 		cin>>a[i];
 		a[i]+=a[i-1];
 	}
 	s=a[n];
 	if(s==1){
 		cout<<-1<<endl;return 0;
 	}
 	vector<int>v;
 	for(int i=2;i<=1e6;i++){
 		if(lp[i]==i){
 			if(s%i==0){
 			           while(s%i==0)s/=i;
 				v.pb(i);
 			}	
 		}
 	}
 	if(s>1){
 		v.pb(s);
 	}
 	int ans=1e18;
 	for(auto j:v){
 		int cnt=0;
 		for(int i=1;i<=n;i++){
 			cnt+=min(a[i]%j,j-a[i]%j);
 		}
 		mins(ans,cnt);
 	}
 	cout<<ans<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
   
    sieve();
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}