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
 	int n,x,y;cin>>n>>x>>y;
 	vector<bool>diff(11,0);

 	auto ask=[&](int j){
 		vector<int>temp;
 		for(int i=1;i<=n;i++){
 			if((1<<j)&i)temp.pb(i);
 		}
 		if(sz(temp)==0)return 0;
 		cout<<"? "<<sz(temp)<<" ";
 		for(auto j:temp)cout<<j<<" ";cout<<endl<<flush;
 		int z;cin>>z;
 		if(z==(x^y))return 1;
 		else 	if(z==y)return 1;
 		return 0;
 	};
 	auto bs=[&](vector<int>temp){
 		int l=0;int r=sz(temp)-1;
 		int ans=0;
 		while(l<=r){
 			int mid=(l+r)/2;
 			cout<<"? "<<mid-l+1<<" ";
 			for(int j=l;j<=mid;j++)cout<<temp[j]<<" ";cout<<endl<<flush;
 			int z;cin>>z;
 			if(z==y){
 				r=mid-1;
 				ans=mid;
 			}	
 			else if(z==(x^y)){
 				r=mid-1;
 				ans=mid;
 			}
 			else{
 				l=mid+1;
 			}
 		}
 		return temp[ans];
 	};
 	for(int i=0;i<=9;i++){
 		diff[i]=ask(i);
 	}
 	for(int i=0;i<=9;i++){
 		if(diff[i]){
 			vector<int>t1,t2;
 			for(int j=1;j<=n;j++){
 				if((1<<i)&j)t1.pb(j);
 				else t2.pb(j);
 			}
 			if(sz(t1)>sz(t2))swap(t1,t2);
 			int p1=bs(t1);
 			int p2=0;
 			for(int j=0;j<=9;j++){
 				int k=(1<<j);
 				if(diff[j]){
 					if((k&p1)==0)p2|=k;
 				}
 				else{
 					if(k&p1)p2|=k;
 				}
 			}
 			if(p1>p2)swap(p1,p2);
 			cout<<"! "<<p1<<" "<<p2<<endl<<flush;
 			exit(0);
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