#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}



#define SIEVE

const int N = 1000050;

int lp[N+1];
int pr[N];int t=0;
int d[N];
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
 	int n,k;cin>>n>>k;
 	int L=1,R=n;
 	int ans=-1;
 	int c=0;
 	rep(i,1,n+1){
 		for(int j=2*i;j<=n;j+=i)d[j]++;
 	}
 	while(L<=R){
 		int M=(L+R)/2;
 		int cnt=0;
 		rep(i,1,M+1){
 			cnt+=M/i-1;
 		}
 		if(cnt>=k){
 			c=cnt;
 			ans=M;
 			R=M-1;
 		}
 		else{
 			L=M+1;
 		}
 	}
 	if(ans==-1){
 		cout<<"No"<<endl;return 0;
 	}cout<<"Yes"<<endl;
 	set<pair<int,int>>st;
 	for(int i=1;i<=ans;i++){
 		int deg=d[i]+ans/i-1;
 		st.insert({deg,i});
 	}
 	while(c>k){
 		auto it=st.lower_bound({c-k,0});
 		if(it->x>c-k)it--;
 		c-=(it->x);
 		st.erase(it);
 	}cout<<sz(st)<<endl;
 	for(auto i:st)cout<<i.y<<" ";cout<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}