#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
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
int a[100005];
int b[100005];
pii dest[100005];
int last[100005];
int solve(){
 int n,m;cin>>n>>m;
 rep(i,1,n+1)cin>>a[i];
 const int bs=200;
 auto get = [&](int x,int bs){
     return x/bs+1;
 };
 auto query= [&](int x,int n){
 	  int cnt=0;
 	  int prev=x;
      while(x<=n){
         cnt+=dest[x].x;
         prev=last[x];
         x=dest[x].y;
         //cout<<x<<endl;
      } 
      return make_pair(prev,cnt);
 };
 for(int i=1;i<=n;i++){
    int cnt=0;
    b[i]=get(i,bs);
    int val=i;
    last[i]=i;
    while(val<=n){
    	cnt++;
    	int v=get(val+a[val],bs);
    	val+=a[val];
    	if(v>b[i] || val>n){
    		dest[i]={cnt,min(n+1,val)};
    		break;
    	}
    	last[i]=val;
    }
    //cout<<dest[i]<<" "<<last[i]<<endl;
 }
 rep3(m){
 	int t;cin>>t;
 	if(t==1){
 		int x;cin>>x;
 		cout<<query(x,n)<<endl;
 	}
 	else{
 		int idx,x;cin>>idx>>x;
 		int cnt=0;
 		a[idx]=x;
 		int val=idx;
 		last[idx]=idx;
 		while(val<=n){
 			cnt++;
 			int v=get(val+a[val],bs);
 			val+=a[val];
 			if(v>b[idx] || val>n){
 				dest[idx]={cnt,min(n+1,val)};
 				break;
 			}
 			last[idx]=val;
 		}
 		for(int j=idx-1;j>0;j--){
 			if(b[j]!=b[idx])break;
 			int val=a[j]+j;
 			if(get(val,bs)>b[idx] || val>n)continue;
 			dest[j].x=dest[j+a[j]].x+1;
 			dest[j].y=dest[j+a[j]].y;
 			last[j]=last[j+a[j]];
 		}
 	}
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