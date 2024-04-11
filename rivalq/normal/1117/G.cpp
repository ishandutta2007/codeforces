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

template<typename T>
struct Fenwick{
    vector<T> tree;
    Fenwick(int n){
        tree.resize(n);
    }

    T query(int i){
        pii sum;
        while(i){
           sum.x+=tree[i].x;
           sum.y+=tree[i].y;
           i-=i&(-i);
       }  
       return sum;
    }
    void update(int i,int n,T val){
       while(i<=n){
          tree[i].x+=val.x;
          tree[i].y+=val.y;
          i+=i&(-i);
       }
    }
};



int solve(){
 	int n,q;cin>>n>>q;
 	vector<int>p(n+1);
 	rep(i,1,n+1)cin>>p[i];
 	stack<pii>st;
 	vector<pii>l(n+1),r(n+1);
 	vector<int>p1(n+1),p2(n+1);
 	Fenwick<pii>fn(n+1);
 	for(int i=1;i<=n;i++){
 			while(!st.empty() && st.top().x<p[i]){
 					r[st.top().y]={i-1,st.top().y};
 					st.pop();
 			}
 			st.push({p[i],i});
 	}
 	while(!st.empty()){
 		r[st.top().y]={n,st.top().y};
 		st.pop();
 	}
 	for(int i=n;i>=1;i--){
 			while(!st.empty() && st.top().x<p[i]){
 					l[st.top().y]={i+1,st.top().y};
 					st.pop();
 			}
 			st.push({p[i],i});
 	}
 	while(!st.empty()){
 		l[st.top().y]={1,st.top().y};
 		st.pop();
 	}
 	for(int i=1;i<=n;i++){
 		p1[i]+=p1[i-1]+l[i].x;
 		p2[i]+=p2[i-1]+r[i].x;
 	}
 	sort(all(r),greater<pii>());
 	sort(all(l));
 	vector<int>ans(q);
 	vector<pair<int,pii>>v(q);
 	rep3(q){
 		cin>>v[i].x;
 	}
 	rep3(q){
 		cin>>v[i].y.x;
 		v[i].y.y=i;
 		ans[i]+=p2[v[i].y.x]-p2[v[i].x-1];
 		ans[i]-=p1[v[i].y.x]-p1[v[i].x-1];
 		ans[i]+=v[i].y.x-v[i].x+1;
 	}
 	sort(all(v));
 	int j=1;
 	for(int i=0;i<q;i++){
 		while(j<=n && l[j].x<v[i].x){
 			pii p={l[j].x,1};
 			fn.update(l[j].y,n,p);
 			j++;
 		}
 		int idx=v[i].y.y;
 		pii p=fn.query(v[i].y.x);
 		pii p2=fn.query(v[i].x-1);p.x-=p2.x,p.y-=p2.y;
 		ans[idx]-=p.y*v[i].x-p.x;
 	}
 	sort(all(v),[&](pair<int,pii>p1,pair<int,pii>p2){return p1.y.x>p2.y.x;});
 	j=1;
 	fn.tree.clear();
 	fn.tree.resize(n+1);
 	for(int i=0;i<q;i++){
 		while(j<=n && r[j].x>v[i].y.x){
 			pii p={r[j].x,1};
 			fn.update(r[j].y,n,p);
 			j++;
 		}
 		int idx=v[i].y.y;
 		pii p=fn.query(v[i].y.x);
 		pii p2=fn.query(v[i].x-1);
 		p.x-=p2.x;p.y-=p2.y;
 		ans[idx]+=p.y*v[i].y.x-p.x;
 	}
 	for(int i=0;i<q;i++){
 		cout<<ans[i]<<" ";
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