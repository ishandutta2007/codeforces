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
int get(string s1,string &s2){
	int n=s1.length();
	int m=s2.length();
    s1.push_back('#');
	for(auto i:s2)s1.push_back(i);
	vector<int>z=z_function(s1);
	for(int i=n+1;i<=n+m;i++){
		if(z[i]==(n+m-i+1))return z[i];
	}	 
	return 0;
}
int solve(){
 int n;cin>>n;
 vector<string>v(n);
 rep3(n)cin>>v[i];
 string ans=v[0];
 for(int i=1;i<n;i++){
 	int k=0;
 	if(ans.length()<=v[i].length())k=get(v[i],ans);
 	else{
 		string temp=ans.substr(ans.length()-v[i].length(),v[i].length());
 		k=get(v[i],temp);
 	}
 	while(k--)ans.pop_back();
 	for(auto i:v[i])ans.push_back(i);
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