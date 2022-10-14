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


int solve(){
 	string s;cin>>s;
 	int n=s.length();
 	int x,y;cin>>x>>y;
 	vector<int>ones(n+1),zeros(n+1);
 	vector<int>t;
 	int res=0;
 	rep(i,1,n+1){
 		if(s[i-1]=='0'){
 			zeros[i]++;
 		}
 		else if(s[i-1]=='1'){
 			ones[i]++;
 		}
 		else{
 			t.pb(i);
 		}
 		ones[i]+=ones[i-1];
 		zeros[i]+=zeros[i-1];
 	}
 	rep(i,1,n+1){
 		if(s[i-1]=='0'){
 			res+=y*ones[i];
 		}
 		else if(s[i-1]=='1'){
 			res+=x*zeros[i];
 		}
 	}
 	int m=sz(t);
 	vector<int>cost_zeros(m+1);
 	vector<int>cost_ones(m+1);
 	for(int i=1;i<=m;i++){
 		int j=t[i-1];
 		int cost_one=x*zeros[j]+y*(zeros[n]-zeros[j]);
 		int cost_zero=y*ones[j]+x*(ones[n]-ones[j]);
 		cost_zeros[i]=cost_zeros[i-1]+cost_zero;
 		cost_ones[i]=cost_ones[i-1]+cost_one;
 	}
 	int ans=1e18;
 	if(x<=y){
 		ans=cost_ones[m];
 		rep(i,1,m+1){
 			int ans_i=cost_ones[m]-cost_ones[i]+cost_zeros[i]+i*(m-i)*x;
 			mins(ans,ans_i);
 		}
 	}
 	else{
 		ans=cost_zeros[m];
 		rep(i,1,m+1){
 			int ans_i=cost_zeros[m]-cost_zeros[i]+cost_ones[i]+i*(m-i)*y;
 			mins(ans,ans_i);
 		}
 	}
 	cout<<ans+res<<endl;
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