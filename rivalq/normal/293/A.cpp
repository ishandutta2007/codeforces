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
	 string s,t;cin>>s>>t;
	 int cnt1=0,cnt2=0,cnt3=0;
	 for(int i=0;i<2*n;i++){
	 	if(s[i]==t[i] && s[i]=='1')cnt1++;
	 	else if(s[i]=='1')cnt2++;
	 	else if(t[i]=='1')cnt3++;
	 }
	 int k1=0;
	 int k2=0;
	 int f=0;
	 while(cnt1>0 || cnt2>0 || cnt3>0){
                if(f==0){
                	if(cnt1>0)k1++,cnt1--;
                	else if(cnt2>0)k1++,cnt2--;
                	else if(cnt3>0)cnt3--;
                }
                else{
                	if(cnt1>0)k2++,cnt1--;
                	else if(cnt3>0)k2++,cnt3--;
                	else if(cnt2>0)cnt2--;
                }
                f^=1;
	 }
	 if(k1==k2){
	 	cout<<"Draw\n";
	 }
	 else if(k1>k2){
	 	cout<<"First\n";
	 }
	 else{
	 	cout<<"Second\n";
	 }
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