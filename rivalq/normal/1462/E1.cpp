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



int solve(){
 	int n;cin>>n;
 	vector<int>a(n+1);
 	vector<int>vec[n+1];
 	rep(i,1,n+1){
 		cin>>a[i];
 		vec[a[i]].pb(i);
 	}
 	auto query=[&](int x,int l,int r){
 		if(x<=0 || x>n)return 0LL;
 		return upper_bound(all(vec[x]),r)-lower_bound(all(vec[x]),l);
 	};
 	int ans=0;
 	rep(i,2,n){
 		// i-2 ,i-1,i,i+1,i+2
 		vector<int>t1(5),t2(5);
 		int L=1,R=i-1;
 		int val=a[i]-2;
 		rep(j,0,5){
 			t1[j]=query(val,L,R);val++;
 		}
 		val=a[i]-2,L=i+1,R=n;
 		rep(j,0,5){
 			t2[j]=query(val,L,R);val++;
 		}
 		ans+=t1[0]*(t2[0]+t2[1]+t2[2]);
 		ans+=t1[1]*(t2[0]+t2[1]+t2[2]+t2[3]);
 		ans+=t1[2]*(t2[0]+t2[1]+t2[2]+t2[3]+t2[4]);
 		ans+=t1[3]*(t2[1]+t2[2]+t2[3]+t2[4]);
 		ans+=t1[4]*(t2[2]+t2[3]+t2[4]);
 	}
 	cout<<ans<<endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}