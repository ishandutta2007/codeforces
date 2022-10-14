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
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
struct node{
	int l,r,p,sz,c;
	bool operator<(const node &rhs)const{
         return (sz==rhs.sz)?p<rhs.p:sz>rhs.sz;
	}
	friend ostream& operator<<(ostream& out,node a){cout<<a.l<<" "<<a.r<<" "<<a.p<<" "<<a.c;return out;}
};
const int maxn=2000005;
int p[maxn];
int sz[maxn];
void clear(int n=maxn){
    rep(i,0,maxn)p[i]=i,sz[i]=1;
}
int root(int x){
   if(x==-1)return -1;	
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    p[p2]=p1;
}
node create(vector<int>&v,int p){
	node temp;
	temp.p=p;
	temp.c=v[0];
	temp.sz=v[1];
	temp.l=v[2];
	temp.r=v[3];
	return temp;
}
int solve(){
 int n;cin>>n;
 vector<int>a(n+1);
 rep(i,1,n+1)cin>>a[i];
 int i=1;
 vector<node>vec;
 vector<int>p[n+1];
 set<node>s;
 while(i<=n){
 	int j=i;
 	int c=a[i];
 	while(j<=n && a[j]==a[i])j++;
 	int sz=j-i;
 	node temp;temp.sz=sz;temp.l=-1;temp.r=-1;
 	temp.p=i;temp.c=a[i];vec.pb(temp);
 	i=j;
 }
 int m=vec.size();
 for(int i=0;i<m;i++){
 	if(i>0)vec[i].l=vec[i-1].p;
 	if(i<m-1)vec[i].r=vec[i+1].p;
 	p[vec[i].p]={vec[i].c,vec[i].sz,vec[i].l,vec[i].r};
 	s.insert(vec[i]);
 }
 int cnt=0;
 while(!s.empty()){
 	node temp=*s.begin();
 	s.erase(s.begin());
 	cnt++;
 	int lp=root(temp.l);
 	int rp=root(temp.r);
 	if(lp==-1 || rp==-1){
 		if(lp>0){
          node left=create(p[lp],lp);
          p[lp][3]=-1;
          s.erase(left);
          left.r=-1;
          s.insert(left);
 		}
 		if(rp>0){
          node left=create(p[rp],rp);
          p[temp.r][2]=-1;
          s.erase(left);
          left.l=-1;
          s.insert(left);
 		}

 	}
 	else if(p[lp][0]==p[rp][0]){
 		// cout<<temp<<endl;
 		 node n=create(p[rp],rp);
 		 s.erase(n);
 		 n=create(p[lp],lp);
 		 s.erase(n);
         p[lp][1]+=p[rp][1];p[lp][3]=p[rp][3];
         merge(lp,rp);
         n=create(p[lp],lp);
         s.insert(n);
         //cout<<n<<endl;
 	}
 	else{
 		 node n=create(p[rp],rp);
 		 s.erase(n);
 		 n=create(p[lp],lp);
 		 s.erase(n);
 		 p[lp][3]=rp;
 		 p[rp][2]=lp;
 		 n=create(p[rp],rp);
 		 s.insert(n);
 		 n=create(p[lp],lp);
 		 s.insert(n);
 	}
 }
 cout<<cnt<<endl;
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
    clear();
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}