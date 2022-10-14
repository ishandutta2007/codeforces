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
 if(n==1){
 	cout<<1<<endl;return 0;
 }
 if(n==2){
 	cout<<1<<" "<<2<<endl;return 0;
 }
 vector<int>v(n+1);
 priority_queue<pii>pq;
 int cnt=1;
 pq.push({n,-(1+n)/2});
 while(!pq.empty()){
 	 pii p=pq.top();
 	 v[-p.y]=cnt++;
 	 //cout<<"#"<<-p.y<<endl;
 	 int len=p.x;
 	 int x=-p.y;
 	 pq.pop();
 	 if(len==1)continue;
 	 if(len==2){
 	 	pq.push({1,-(x+1)});
 	 	continue;
 	 }
 	 int len1=len-len/2-1;
	 int l1=x+1;
	 int r1=x+len/2;
	 int mid;
	 if((r1-l1+1)%2){
	 		pii temp={len/2,-(l1+r1)/2};
	 		pq.push(temp);
	 }
	 else{
	 		pii temp={len/2,-(l1+r1-1)/2};
	 		pq.push(temp);
	 }
	 int l2=x-len1;
	 int r2=x-1;
	 if((r2-l2+1)%2){
	 		pii temp={len1,-(l2+r2)/2};
	 		pq.push(temp);
	 }
	 else{
	 		pii temp={len1,-(l2+r2-1)/2};
	 		pq.push(temp);
	 }
 }
 for(int i=1;i<=n;i++)cout<<v[i]<<" ";cout<<endl;
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