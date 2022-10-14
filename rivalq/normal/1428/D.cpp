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
#define hell           10000000000007LL
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 	int n;cin>>n;
 	vector<int>t1,t2;
 	set<int>row;
 	rep(i,1,n+1){
 		row.insert(i);
 	}
 	set<pii>ans;
 	rep(i,1,n+1){
 		int t;cin>>t;
 		if(t==1){
 			if(t1.size()>0){
 				int p=t1.back();t1.pop_back();
 				if(row.empty()){
 					cout<<-1<<endl;return 0;
 				}
 				int r=*row.begin();row.erase(r);
 				ans.insert({p,i});
 				ans.insert({r,i});
 			}
 			else if(t2.size()>0){
 				int p=t2.back();t2.pop_back();
 				ans.insert({p,i});
 			}
 			else{    
 				if(row.empty()){
 					cout<<-1<<endl;return 0;
 				}
 				int r=*row.begin();row.erase(r);
 				ans.insert({r,i});
 			}
 		}
 		else if(t==2){
 			if(t1.size()>0){
 				int p=t1.back();t1.pop_back();
 				if(row.empty()){
 					cout<<-1<<endl;return 0;
 				}
 				int r=*row.begin();row.erase(r);
 				ans.insert({p,i});
 				ans.insert({r,i});
 				t2.push_back(r);
 			}
 			else{
 				if(row.empty()){
 					cout<<-1<<endl;return 0;
 				}
 				int r=*row.begin();row.erase(r);
 				ans.insert({r,i});
 				t2.push_back(r);
 			}
 		}
 		else if(t==3){
 			if(t1.size()>0){
 				int p=t1.back();t1.pop_back();
 				if(row.empty()){
 					cout<<-1<<endl;return 0;
 				}
 				int r=*row.begin();row.erase(r);
 				ans.insert({p,i});
 				ans.insert({r,i});
 				t1.push_back(r);
 			}
 			else{
 				int r=*row.begin();row.erase(r);
 				ans.insert({r,i});
 				t1.push_back(r);
 			}
 		}
 	}
 	if(t2.size() || t1.size()){
 		cout<<-1<<endl;return 0;
 	}
 	cout<<sz(ans)<<endl;
 	for(auto i:ans)cout<<i<<endl;
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