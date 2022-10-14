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
 	int n,k;cin>>n>>k;
 	vector<int>v[k+2];
 	set<int>st;
 	rep(i,1,n+1)st.insert(i);
 	rep(j,1,k+1){
 		int c;cin>>c;
 		rep3(c){
 			int t;cin>>t;
 			st.erase(t);
 			v[j].pb(t);
 		}
 	}
 	for(auto i:st){
 		v[k+1].pb(i);
 	}
 	auto ask=[&](int l,int r){
               vector<int>g;
               rep(i,l,r+1){
               		for(auto j:v[i])g.pb(j);
               }
               cout<<"? "<<sz(g)<<" ";
               rep3(sz(g))cout<<g[i]<<" ";cout<<endl;cout<<flush;
               int x;cin>>x;
               return x;
 	};
 	auto print=[&](int mx1,int mx2,int j){
 		cout<<"! ";
 		rep(i,1,k+1){
 			if(i==j)cout<<mx2<<" ";
 			else cout<<mx1<<" ";
 		}cout<<endl;cout<<flush;
 		string s;cin>>s;
 	};
 	if(k==1){
 		set<int>s;rep3(n)s.insert(i+1);
 		rep3(sz(v[1]))s.erase(v[1][i]); 
 		cout<<"? "<<sz(s)<<" ";
 		for(auto i:s)cout<<i<<" ";cout<<endl;cout<<flush;
 		int x;cin>>x;
 		cout<<"! "<<x<<endl;cout<<flush;
 		string st;cin>>st;return 0;	
 	}
 	int l=1;
 	int r=k+1;
 	int mx1=ask(1,k+1),mx2=0;
        int idx=0;
 	while(l<r){
 		int mid=(l+r)/2;
 		int x=ask(l,mid);
 		if(x==mx1){
 			r=mid;
                        idx=l; 
 		}
 		else{
 			l=mid+1;
 			idx=r;
 		}
 	}
 	set<int>s;rep3(n)s.insert(i+1);
 	rep3(sz(v[idx]))s.erase(v[idx][i]); 
 	cout<<"? "<<sz(s)<<" ";
 	for(auto i:s)cout<<i<<" ";cout<<endl;cout<<flush;
 	int x;cin>>x;
        mx2=x;
 	print(mx1,mx2,idx);
 return 0;
}
signed main(){
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