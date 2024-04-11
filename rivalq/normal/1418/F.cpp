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


#define SIEVE

const int N = 2e5+5;

int lp[N+1];
int pr[N];int t=0;

int cnt=0;

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


struct node{
    pii a;
    void merge(node &n1,node &n2){
        this->a=min(n1.a,n2.a);
    }
};

template<typename node>
struct segtree{
  node t[4*N];
  int tl[4*N];
  int tr[4*N];
  void build(int v,int start,int end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a={lp[start],start};
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  pii query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return {1e9,1e9};
      if(l<=tl[v] && tr[v]<=r){
         return t[v].a;
      }
      pii a=query(2*v,l,r);
      pii b=query(2*v+1,l,r);
      return min(a,b);
  }
public:
  pii query(int l,int r){
      return query(1,l,r);
  }   
};

segtree<node>seg;

map<int,int>mp;

vector<int>fac[N];
vector<int>mul[N];

int solve(){
 	int n,m,l,r;cin>>n>>m>>l>>r;
 	seg.build(1,2,2e5);
 	int sl=max(2LL,l);
 	int sr=min(m,r);
 	int k=1;
 	while(k<n && sl>sr){
 		k++;
 		cout<<-1<<endl;
 		sl=max(2LL,l/k+(l%k!=0));
 		sr=min(m,r/k);
 	}
 	//cout<<k<<" "<<sl<<" "<<sr<<endl;
 	for(int i=sl;i<=sr;i++){
 		for(auto j:fac[i])mp[j]++;
 	}
 	auto del=[&](int x){
 		for(auto j:fac[x]){
 			mp[j]--;
 			if(mp[j]==0)mp.erase(j);
 		}
 	};	
 	auto add=[&](int x){
 		for(auto j:fac[x]){
 			mp[j]++;
 		}
 	};
 	auto get=[&](int l,int a){
 		int idx=lower_bound(all(mul[a]),l)-mul[a].begin();
 		return mul[a][idx];
 	};

 	rep(i,k,n+1){
 		int L=2;
 		maxs(L,l/i+(l%i!=0));
 		int R=m;
 		mins(R,r/i);
 		while(sl>L){
 			add(--sl);
 		}
 		while(sr>R){
 			del(sr--);
 		}
 		
 		if(L>R){
 			cout<<-1<<endl;
 			continue;
 		}
 		auto s=seg.query(L,R);
 		int x2,y2,y1;
 		bool found=0;
 		for(auto j:fac[i]){
 			 auto itr=mp.upper_bound(j);
 			 if(itr!=mp.end()){
 				int val=(i/j)*itr->x;
 				if(val<=n){
 						found=1;
 						x2=val;
 						y1=get(L,itr->x);
 						y2=(i*y1)/x2;
 						break;
 					}
 				}
 			}
 		if(!found)cout<<-1<<endl;
 		else cout<<i<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
 		
 	}
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int i=1;i<=2e5;i++){
    	for(int j=i;j<=2e5;j+=i){
    		fac[j].pb(i);
    		mul[i].pb(j);
    	}
    }
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