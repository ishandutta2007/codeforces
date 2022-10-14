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
const int maxn=2000005;
unordered_map<int,pii>p;
unordered_map<int,int>sz;
pii root(int x){
   if(p.count(x)==0)p[x]={x,0},sz[x]++;	
   if(x!=p[x].x){
   	   int dis=p[x].y;
       p[x]=root(p[x].x);
       p[x].y^=dis;
   }
   return p[x];  
}
void merge(int x,int y,int w){
    pii p1=root(x);
    pii p2=root(y);
    if(p1.x==p2.x)return;
    if(sz[p1.x]<sz[p2.x])swap(p1,p2);
    p[p2.x]={p1.x,w^p1.y^p2.y};
    sz[p1.x]+=sz[p2.x];
    sz[p2.x]=0;
    return;
}

int solve(){
 int q;cin>>q;
 int last=0;
 rep3(q){
 	int t;cin>>t;
 	int l,r;cin>>l>>r;
 	l=l^last;
 	r=r^last;
 	if(l>r)swap(l,r);
 	r++;
 	if(t==1){
 		int x;cin>>x;x=x^last;
 		if(root(l).x==root(r).x)continue;
 		merge(l,r,x);
 	}
 	else{
 		if(root(l).x!=root(r).x){
 			last=1;
 			cout<<-1<<endl;continue;
 		}
 		last=root(l).y^root(r).y;
 		cout<<last<<endl;
 	}
 	//cout<<root(0).y<<endl;
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