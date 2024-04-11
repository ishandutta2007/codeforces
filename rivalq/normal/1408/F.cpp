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
 	set<pair<int,set<int>>>st;
 	vector<int>temp;
 	vector<int>a(n+1);
 	rep(i,1,n+1)a[i]=i;
 	int c=n;
 	for(int j=16;j>=0;j--){
 		if((1<<j)&n){
 			temp.pb(1<<j);
 		}
 	}
 	int len=1;
 	vector<pii>ans;
 	for(auto i:temp){
 		vector<int>v;
 		for(int k=len;k<len+i;k++){
 			v.pb(k);
 		}
 		set<pair<int,set<int>>>s;
 		for(auto j:v){
 			set<int>s1;
 			s1.insert(j);
 			s.insert({1,s1});
 		}
 		while(sz(s)>1){
 			auto itr1=s.begin();
 			auto itr2=itr1;itr2++;
 			set<int>t;
 			set<int>t1=itr1->y;
 			set<int>t2=itr2->y;
 			while(!t1.empty()){
 				int v1=*t1.begin();
 				int v2=*t2.begin();
 				ans.eb(v1,v2);
 				t1.erase(t1.begin());
 				t2.erase(t2.begin());
 				t.insert(v1),t.insert(v2);
 			}
 			s.erase(itr1);
 			s.erase(itr2);
 			s.insert({sz(t),t});
 		}
 		auto itr=s.begin();
 		st.insert({itr->x,itr->y});
 		len+=i;
 	}
 	int k=1;
 	while(sz(st)>2){
 		auto itr1=st.rbegin();
 		auto itr2=st.begin();
 		auto itr3=itr2;
 		itr3++;
 		if(itr2->x==itr3->x){
 			set<int>t;
 			set<int>t1=itr2->y;
 			set<int>t2=itr3->y;
 			while(!t1.empty()){
 				int v1=*t1.begin();
 				int v2=*t2.begin();
 				ans.eb(v1,v2);
 				t1.erase(t1.begin());
 				t2.erase(t2.begin());
 				t.insert(v1),t.insert(v2);
 			}
 			st.erase({itr2->x,itr2->y});
 			st.erase({itr3->x,itr3->y});
 			st.insert({sz(t),t});
 			continue;
 		}
 		set<int>t1;
 		set<int>del1=itr1->y;
 		set<int>del2=itr2->y;
 		while(!del2.empty()){
 				int v1=*del1.begin();
 				int v2=*del2.begin();
 				ans.eb(v1,v2);
 				del1.erase(v1);
 				del2.erase(v2);
 				t1.insert(v1);
 				t1.insert(v2);
 		}
 		st.erase({itr1->x,itr1->y});
 		st.erase({itr2->x,itr2->y});
 		st.insert({sz(t1),t1});
 		st.insert({sz(del1),del1});
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