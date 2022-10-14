#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order
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


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int N = 1000050;
const int M=2e7;
int lp[N+1];
int pr[N];int t=0;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


void sieve(){
    for (int i=2; i<N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[t++]=i;
            }
        for (int j=0; j<t && pr[j]<=lp[i] && i*pr[j]<N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}


int solve(){
 	int n;cin>>n;
 	sieve();
 	int ans=1;
 	int q=9999;
 	for(int i=2;i<=min(320LL,n) && ans<=n;i++){
 		if(lp[i]==i){
 			cout<<"B"<<" "<<i<<endl<<flush;
 			int x;cin>>x;
 			cout<<"A"<<" "<<i<<endl<<flush;
 			int y;cin>>y;
 			q-=2;
 			if(y==0){
 				continue;
 			}
 			int val=i;
 			int l=1,r=l;
 			while(val*i<=n){
 				val*=i;
 				r++;
 			}
 			int kk=1;
 			while(l<=r){
 				int mid=(l+r)/2;
 				int z=pow(i,mid);
 				cout<<"A"<<" "<<z<<endl<<flush;
 				q--;
 				int y;cin>>y;
 				if(y){
 					kk=z;
 					l=mid+1;
 				}
 				else{
 					r=mid-1;
 				}
 			}
 			ans*=kk;
 		}
 	}
 	if(n<=320 || ans>=320){
 		cout<<"C "<<ans<<endl<<flush;return 0;
 	}
 	if(ans>1){
 		for(int i=321;i<=n;i++){
 			if(ans*i>n)break;
 			if(lp[i]==i){
 				cout<<"A"<<" "<<ans*i<<endl<<flush;
 				int z;cin>>z;
 				if(z>0){
 					ans*=i;break;
 				}
 			}
 		}
 		cout<<"C "<<ans<<endl<<flush;return 0;
 	}
 	vector<int>temp,vec;
 	for(int i=321;i<=n;i++){
 		if(ans*i>n)break;
 		if(lp[i]==i){
 			temp.pb(i);
 		}
 	}
 	int c=0;
 	cout<<"A"<<" "<<1<<endl<<flush;
 	int cnt;cin>>cnt;
 	for(int i=0;i<sz(temp);i++){
 		cout<<"B"<<" "<<temp[i]<<endl<<flush;
 		cnt--;vec.pb(temp[i]);c++;
 		int x;cin>>x;
 		if(c%95==0){
 			cout<<"A"<<" "<<1<<endl<<flush;
 			int z;cin>>z;
 			if(z==cnt){
 				vec.clear();
 			}
 			else{
 				break;
 			}
 		}
 	}
 	for(auto j:vec){
 		cout<<"A"<<" "<<j<<endl<<flush;
 		int z;cin>>z;
 		if(z>0){
 			ans*=j;break;
 		}
 	}
 	cout<<"C"<<" "<<ans<<endl<<flush;
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