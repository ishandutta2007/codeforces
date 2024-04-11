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
 	vector<int>a(n+1);
 	int x=0;
 	set<pii>st;
 	map<int,int>mp;
 	rep(i,1,n+1){
 		cin>>a[i];
 		x^=a[i];
 		st.insert({a[i],i});mp[a[i]]++;
 	}
 	vector<array<int,3>>ans;
 	auto f = [&] (pii val,set<pii>st,int th){
 		while(st.size()>th){
 			pii p1=*st.begin();st.erase(p1);
 			pii p2=*st.begin();st.erase(p2);
 			pii p3=*st.begin();st.erase(p3);
 			int x=(p1.x^p2.x^p3.x);
 			ans.pb({p1.y,p2.y,p3.y});
 			ans.pb({p1.y,p2.y,val.y});p3.x=(p1.x^p2.x^p3.x);
 			st.insert(p3);
 		}
 		if(th==2){
 			pii p1=*st.begin();st.erase(p1);
 			pii p2=*st.begin();st.erase(p2);
 			ans.pb({p1.y,p2.y,val.y});
 			a[p1.y]=(p1.x^p2.x^val.x);
 			a[p2.y]=(p1.x^p2.x^val.x);
 		}
 	};
 	if(n&1){
 		cout<<"YES"<<endl;
 		for(int i=2;i<=n;i+=2){
 			int x=a[1]^a[i]^a[i+1];
 			a[1]=x,a[i]=x,a[i+1]=x;
 			ans.pb({1,i,i+1});
 		}
 		for(int i=2;i<=n;i+=2){
 			int x=a[1]^a[i]^a[i+1];
 			a[1]=x,a[i]=x,a[i+1]=x;
 			ans.pb({1,i,i+1});
 		}
 		cout<<sz(ans)<<endl;
 		for(auto i:ans){
 				cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
 		}
 	}
 	else{
 		if(x!=0){
 			cout<<"NO"<<endl;return 0;
 		}
 		else{
 			cout<<"YES"<<endl;
 			pii val=*st.begin();
 			st.erase(st.begin());f(val,st,1);
 			cout<<sz(ans)<<endl;
 			for(auto i:ans){
 				cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
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