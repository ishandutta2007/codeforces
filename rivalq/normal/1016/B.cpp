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
vector<int> z_function(string &s) {
    int n=s.length();
    vector<int> z(n);
    for (int i=1,l=0,r=0;i<n;++i) {
        if (i<=r)z[i]=min(r-i+1,z[i-l]);
        while (i+z[i]<n && s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    return z;
}

int solve(){
 	int n,m,q;cin>>n>>m>>q;
 	string s,t;cin>>s>>t;
 	vector<int>p(n+1,0);
 	t.pb('#');
 	for(auto i:s)t.pb(i);
 	vector<int>z=z_function(t);
 	for(int i=m+1;i<=m+n;i++){
 		if(z[i]==m)p[i-m]++;
 		p[i-m]+=p[i-1-m];
 	} 
 	rep3(q){
 		int l,r;cin>>l>>r;
 		r=r-m+1;
 		if(l>r){
 			cout<<0<<endl;
 		}
 		else cout<<p[r]-p[l-1]<<endl;
 	}
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