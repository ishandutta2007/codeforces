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
 	string temp;
 	string s,t;cin>>s>>t;
 	int c=0;
 	for(int i=0;i<n;i++){
 		if(s[i]!=t[i])temp.push_back(s[i]);
 	}
 	for(auto i:temp){
 		if(i=='0')c++;
 		else c--;
 	}
 	if(c){
 		cout<<-1<<endl;
 		return 0;
 	}
 	int res=0;
 	int m=temp.length();
 	vector<int>a(m+1),p(m+1);
 	for(int i=0;i<m;i++){
 		a[i+1]=(temp[i]=='0')?-1:1;
 		p[i+1]=p[i]+a[i+1];
	}
	int mn=0;
	for(int i=1;i<=m;i++){
		maxs(res,p[i]-mn);
		mins(mn,p[i]);
	}
	for(int i=1;i<=m;i++){
		a[i]=(a[i]==-1)?1:-1;
		p[i]=p[i-1]+a[i];
	}
	mn=0;
	for(int i=1;i<=m;i++){
		maxs(res,p[i]-mn);
		mins(mn,p[i]);
	}
	cout<<res<<endl;
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