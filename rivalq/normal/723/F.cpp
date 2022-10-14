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
int p[maxn];
int sz[maxn];
bool s1[maxn];
bool s2[maxn];
void clear(int n=maxn){
    rep(i,0,maxn)p[i]=i,sz[i]=1;
}
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return;
    if(s1[p1] && s2[p1])p[p2]=p1;
    else if(s1[p2] && s2[p2])p[p1]=p2;
    else if(s1[p1] || s2[p1])p[p2]=p1;
    else p[p1]=p2;
}

int solve(){
 	int n,m;cin>>n>>m;
 	vector<int>g[n+1];
 	vector<pii>edges;
 	vector<pii>st;
 	rep(i,1,m+1){
 		int a,b;cin>>a>>b;
 		g[a].pb(b);
 		g[b].pb(a);
 		edges.eb(a,b);
 	}
 	int s,t,ds,dt;cin>>s>>t>>ds>>dt;
 	for(auto j:g[s]){
                 s1[j]=1;
 	}
 	for(auto j:g[t]){
 		 s2[j]=1;
 	}
 	for(auto j:edges){
 		if(j.x==s || j.x==t || j.y==s || j.y==t)continue;
 		if(root(j.x)==root(j.y))continue;
 		merge(j.x,j.y);
 		st.eb(j.x,j.y);
        }
        int cnts=0,cntt=0,cntst=0;
        set<int>sts;
        vector<int>ss(n+1,0),tt(n+1,0);
        rep(i,1,n+1){
        	if(i==s || i==t)continue;
        	int p=root(i);
        	if(s1[i])ss[p]=i;
        	if(s2[i])tt[p]=i;
        	sts.insert(p);
        } 
        for(auto i:sts){
        	if(ss[i] && tt[i])cntst++;
        	else if(ss[i])cnts++;
        	else cntt++;
        }
        if(cnts>ds || cntt>dt || cntst+cntt+cnts>ds+dt){
        	cout<<"No"<<endl;return 0;
        }
        if(cntst==0 && (cnts+1>ds || cntt+1>dt)){
        	cout<<"No"<<endl;return 0;
        }
        if(cntst==0){
        	st.eb(s,t);
        	merge(s,t);
        	ds--,dt--;
        }
        for(auto i:sts){
        	if(ss[i] && tt[i]==0)st.eb(s,ss[i]),ds--,merge(s,ss[i]);
        	else if(tt[i] && ss[i]==0)st.eb(t,tt[i]),dt--,merge(t,tt[i]);
        	else {
        		if(ds>=dt)st.eb(s,ss[i]),ds--,merge(s,ss[i]);
        		else st.eb(t,tt[i]),dt--,merge(t,tt[i]);
        	}
        }
        if(root(s)!=root(t)){
        	bool f=0;
        	if(ds){
        		for(auto i:g[s]){
        			if(dt==0 && i==t)continue;
        			if(root(i)!=root(s)){
        				f=1;
        				st.eb(s,i);break;
        			}
        		}
        	}
        	if(f==0 && dt){
        		for(auto i:g[t]){
        			if(ds==0 && i==s)continue;
        			if(root(i)!=root(t)){
        				f=1;
        				st.eb(t,i);break;
        			}
        		}
        	}
        	if(f==0){
        		cout<<"No"<<endl;return 0;
        	}
        }
        cout<<"Yes"<<endl;

        for(auto i:st)cout<<i<<endl;
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