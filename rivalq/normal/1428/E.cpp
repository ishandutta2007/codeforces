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
#define hell           10000000000007LL
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 	int n,kk;cin>>n>>kk;
 	set<pair<int,pii>>st;
 	vector<int>v(n+1);
 	auto change=[&](pair<int,pii> p){
 		int k=p.y.y+1;
 		int a=v[p.y.x];
 		int k2=p.y.y;
 		int t=(a/k)*(a/k)*(k-a%k) + (a/k+1)*(a/k+1)*(a%k);
 		int t2=(a/k2)*(a/k2)*(k2-a%k2) + (a/k2+1)*(a/k2+1)*(a%k2);
 		p.x=t-t2;
 		p.y.y++;
 		return p;
 	};
 	int ans=0;
 	rep(i,1,n+1){
 		int t;cin>>t;v[i]=t;
 		pair<int,pii>p={t*t,{i,1}};
 		ans+=t*t;
 		st.insert(change(p));
 	}
 	kk-=n;
 	while(kk--){
 		auto s=*st.begin();
 		st.erase(st.begin());
 		ans+=s.x;
 		if(s.y.y==v[s.y.x])continue;
 		s=change(s);
 		st.insert(s);
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}