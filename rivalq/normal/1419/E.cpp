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
 	vector<int>ans={n};
 	int t=n;
 	map<int,int>mp;
 	for(int i=2;i<=1e5;i++){
 		if(lp[i]==i && t%i==0){
 			while(t%i==0)t/=i,mp[i]++;
 		}
 	}
 	if(t>1)mp[t]++;
 	function<void(int,vector<pii>&,int val)> dfs = [&](int i,vector<pii>&v,int val){
 		if(i==sz(v)){
 			if(val!=n)ans.pb(val);return;
 		}
 		int z=1;
 		for(int j=0;j<=v[i].y;j++){
 			int nv=val*z;
 			dfs(i+1,v,nv);
 			z*=v[i].x;
 		}
 	};
 	vector<pii>vec;
 	for(auto i:mp){
 		vec.eb(i.x,i.y);
 	}
 	for(int i=0;i<sz(vec);i++){
 		vector<pii>v;
 		for(int j=i+1;j<sz(vec);j++){
 			v.pb(vec[j]);
 		}
 		int z=1;
 		for(int j=1;j<=vec[i].y;j++)z*=vec[i].x;
 		for(int j=1;j<=vec[i].y;j++){
 			dfs(0,v,z);
 			z/=vec[i].x;
 		}
 	}
 	int cnt=0;
 	int m=sz(ans);
 	for(int i=0;i<sz(ans);i++){
 		if(gcd(ans[i],ans[(i+1)%m])==1)cnt++;
 	}
 	for(auto i:ans)cout<<i<<" ";cout<<endl;
 	cout<<cnt<<endl;

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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}