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
	if(n<3){
	    	cout<<0<<endl;return 0;
	}
	map<pair<int,pii>,int>mp;
	map<int,int>mp2;
        for(int i=0;i<=1000;i++){
           mp2[i*i-i]=i;
        } 
	int ans=n*(n-1)*(n-2)/6;
	vector<pii>p(n+1);
	rep(i,1,n+1){
	      cin>>p[i];
	}
	rep(i,1,n+1){
		rep(j,i+1,n+1){
                    int dy=p[j].y-p[i].y;
                    int dx=p[j].x-p[i].x;
                    int val=dx*p[i].y-dy*p[i].x;
                    int g=gcd(dy,dx);
                    g=gcd(g,val);
                    dy/=g,dx/=g,val/=g;
                    if(dy<0)dy*=-1,dx*=-1,val*=-1;
                    mp[{dx,{-dy,val}}]+=2; 
		}
	}
	for(auto i:mp){
		i.y=mp2[i.y];
		if(i.y>2){
			ans-=(i.y)*(i.y-1)*(i.y-2)/6;
		}
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