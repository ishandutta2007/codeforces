// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
//#define int            long long
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




const int N = 1e6 + 5;

struct node{
    int a=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
       a = n1.a + n2.a;
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
          t[v].a = 0;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,int val){
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].a += val;
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  int find(int v,int l,int r,int &k){
  	if(tr[v]<l || tl[v]>r)return -1;
  	if(l<=tl[v] && tr[v]<=r){
        	   if(k <= t[v].a){
        	   	while(tl[v] != tr[v]){
        	   		if(k <= t[2*v].a){
        	   			v = 2*v;
        	   		}else{
        	   			k -= t[2*v].a;
        	   			v = 2*v + 1;
        	   		}
        	   	}
        	   	return tl[v];
        	   }else{
        	   	k -= t[v].a;
        	   	return -1;
        	   }
      	}
      	int a = find(2*v,l,r,k);
      	if(a == -1)return find(2*v + 1,l,r,k);
      	return a;
  }
public:
  
  void upd(int l,int r,int val){
      return zeno(1,l,r,val);
  }   
};

segtree<node>seg;

template<typename T>
struct Fenwick{
    vector<T> tree;
    Fenwick(int n){
        tree.resize(n);
    }

    T query(int i){
        int sum=0;
        while(i){
           sum+=tree[i];
           i-=i&(-i);
       }  
       return sum;
    }
    void update(int i,int n,T val){
       while(i<=n){
          tree[i]+=val;
          i+=i&(-i);
       }
    }

    int bit_search(int v){
	int sum = 0;
	int pos = 0;
	
	for(int i = 20; i >= 0; i--){
		if(pos + (1 << i) < sz(tree) and sum + tree[pos + (1 << i)] < v){
			sum += tree[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
    }

};



int solve(){
 		int n,q; cin >> n >> q;
 		vector<int>a(n + 1);
 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 		}
 		vector<vector<int>> g(n + 1);
 		for(int i = 2; i <= n; i++){
 			int x; cin >> x;
 			g[x].push_back(i);
 		}
 		vector<int> fr(n + 1);
 		vector<set<int>> st(n + 1);
 		vector<vector<pair<pii,int>>> queries(n + 1);
 		vector<int> ans(q,-1);
 		for(int i = 0; i < q; i++){
 			int v,l,k; cin >> v >> l >> k;
 			queries[v].push_back({{l,k},i});
 		}
 		int cnt = 0;
 		//seg.build(1,1,n);
 		Fenwick<int> fn(n + 1);
 		auto update_fenwick = [&](int i,int val){
 			//int j = n - i + 1;
 			fn.update(i,n,val);
 			//seg.upd(i,i,val);
 		};

 		auto find_ans = [&](int j,int l,int k){
 			k += fn.query(l - 1);
	 		int q = fn.bit_search(k);
 			if(q <= n){
	 			ans[j] = *st[q].begin();
 			}
 			
 		};	

 		auto add = [&](int val){
 			int old_fr = fr[val];
 			if(old_fr > 0){
 				st[old_fr].erase(val);
	 			update_fenwick(old_fr,-1);	
 			}
 			fr[val]++;
 			old_fr++;
 			st[old_fr].insert(val);
 			update_fenwick(old_fr,1);
 		};

 		auto remove = [&](int val){
 			int old_fr = fr[val];
 			st[old_fr].erase(val);
 			update_fenwick(old_fr,-1);
 			fr[val]--;
 			old_fr--;
 			if(old_fr > 0){
 				st[old_fr].insert(val);
 				update_fenwick(old_fr,1);	
 			}
 		};

 		function<void(int)> dfs = [&](int u){
 			add(a[u]);
 			cnt++;
 			for(auto i:queries[u]){
 				int l = i.x.x;
 				int k = i.x.y;
 				int j = i.y;
 				find_ans(j,l,k);
 			}
 			for(auto i:g[u]){
 				dfs(i);
 			}
 			cnt--;
 			remove(a[u]);
 		};
 		dfs(1);
 		for(auto i:ans)cout << i << " ";
 			cout << endl;

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