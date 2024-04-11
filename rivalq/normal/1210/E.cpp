#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
//#define int            long long
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



const int N=200;
const int M=1e6+5;

int rev[M],mp[N];
int bij[N][N];

int k,t;

int fact(int k){
	return (k==0)?1:k*fact(k-1);
}

int comp(int a,int b){
	// finds composition of a->b
	a=mp[a],b=mp[b];
	vector<int>p1(k+1),p2(k+1);
	int cnt=1;
	while(cnt<=k){
		p1[k-cnt+1]=a%10;a/=10;
		p2[k-cnt+1]=b%10;b/=10;
		cnt++;
	}
	int c=0;
	rep(i,1,k+1){
		c=c*10+p1[p2[i]];
	}
	return rev[c];
}

vector<int>reach;
int vis[200];


int count(int i){
	if(vis[i])return sz(reach);
	queue<int>q;
	q.push(i);
	while(!q.empty()){
		int v=q.front();q.pop();
		reach.pb(v);vis[v]=1;
		for(auto i:reach){
			int k=bij[v][i];
			if(!vis[k]){
				q.push(k);
				vis[k]=1;
			}
		}
	}
	return sz(reach);
}


int solve(){
 		int n;cin>>n>>k;
 		t=fact(k);
 		vector<int>p(k);
 		rep(i,0,k)p[i]=i+1;
 		int cnt=0;
 		do{
 			int c=0;
 			for(auto i:p){
 				c=c*10+i;
 			}
 			mp[++cnt]=c;rev[c]=cnt;
 		}while(next_permutation(p.begin(),p.end()));
 		rep(i,1,t+1){
 			rep(j,1,t+1){
 				bij[i][j]=comp(i,j);
 			}
 		}
 		vector<int>last(t+1,-1);
 		ll ans=0;
 		set<pii>aux;
 		aux.insert({0,0});
 		auto solve = [&](int i){
 			int cur=0;
 			int last=i;
 			for(auto i:aux){
 				ans+=cur*(last+i.x);
 				if(i.y==0)break;
 				if(cur<t){
 					cur=count(i.y);
 				}
 				last=-i.x;
 			} 
 			mem0(vis);reach.clear();
 		};
 		rep(i,1,n+1){
 			int c=0;
 			rep(j,0,k){
 				int t;cin>>t;
 				c=c*10+t;
 			}
 			c=rev[c];
 			aux.erase({-last[c],c});
 			last[c]=i;
 			aux.insert({-last[c],c});
 			solve(-i);
 		}
 		cout<<ans<<endl;
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