// Jai Shree Ram  
  
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
 	int n;cin>>n;
 	vector<int>a(n+1);
 	vector<int>p(n+1),s(n+1);
 	rep(i,1,n+1){
 		cin>>a[i];
 	}
 	p[1]=0;
 	rep(i,2,n+1){
 		if(a[i-1]<p[i-1]){
 			for(int j=i;j<=n;j++)p[j]=-1;
 				break;
 		}
 		else{
 			p[i]=a[i-1]-p[i-1];
 		}
 	}	
 	s[n]=0;
 	for(int i=n-1;i>=1;i--){
 		if(a[i+1]<s[i+1]){
 			for(int j=i;j>=1;j--)s[j]=-1;
 			break;	
 		}
 		else{
 			s[i]=a[i+1]-s[i+1];
 		}
 	}
 	if(p[n]==a[n]){
 		cout<<"YES\n";return 0;
 	}
 	auto check=[&](vector<int>v){
 		for(int i=1;i<4;i++){
 			if(v[i]<v[i-1]){
 				return false; 
 			}
 			else{
 				v[i]-=v[i-1];
 			}
 		}
 		return v.back()==0;
 	};
 	for(int i=1;i<n;i++){
 		// check for i,i+1
 		// piles = {p[i],a[i+1],a[i],s[i+1]};
 		if(p[i]==-1 || s[i+1]==-1){
 			continue;
 		}
 		if(check({p[i],a[i+1],a[i],s[i+1]})){
 			cout<<"YES"<<endl;return 0;
 		}
 	}	
 	cout<<"NO"<<endl;
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