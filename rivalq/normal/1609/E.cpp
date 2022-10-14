// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
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


template<typename T>
class matrix{
    public:
    vector<vector<T>> val;
    int n;
    matrix<T>(int size){
        n=size;
        val.resize(n);
        rep(i,0,n)val[i].resize(n);
    }
    matrix<T> operator+(const matrix<T>&) const;
    matrix<T> operator-(const matrix<T>&) const;
    matrix<T>& operator=(const matrix<T>& b){
        val=b.val;
        n=b.n;
        return *this;
    }
    void set(int x){
        rep(i,0,n){
            rep(j,0,n){
                val[i][j]=x;
            }
        }
    }
    void print(){
        rep(i,0,n){
            rep(j,0,n){
                cout<<val[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    matrix<T> mul(T a){
        matrix<T> ans(this->n);
        rep(i,0,this->n){
            rep(j,0,this->n){
                ans.val[i][j]=a*this->val[i][j];
            }
        }
        return ans;
    }
    matrix<T> operator*(const matrix<T>& b) const{
        matrix<T> ans(b.n);
        ans.set(hell);
        rep(i,0,b.n){
            rep(j,0,b.n){
              rep(k,0,b.n){
                  mins(ans.val[i][j],this->val[i][k] + b.val[k][j]);
              }
           }
        }
        return ans;			
    }
    matrix<T> identity(int N){
       matrix<T> ans(N);
       rep(i,0,N){
          ans.val[i][i]=1;
       }
       return ans;
    }
    matrix<T> matexpo(matrix<T> a, int n){
        if(n==0){
          return identity(a.n);
        }
        if(n==1) return a;
        matrix<T> x=matexpo(a,n/2);
        matrix<T> r=x*x;
        if(n&1) r=r*a;
        return r;
   }

};

const int N = 1e5 + 5;


struct node{
    matrix<int> dp = matrix<int>(3);
    node (){
        //dp = matrix<int>(3);
    }
    void merge(node &n1,node &n2){
         dp = n1.dp * n2.dp;
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
          t[v].dp = t[v].dp.identity(3); 
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,matrix<int>&val){
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].dp = val;
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  
public:
 
  void upd(int l,int r,matrix<int> val){ 	
      return zeno(1,l,r,val);
  }   
};
segtree<node> seg;

int solve(){
 		int n,q; cin >> n >> q;
 		seg.build(1,1,n);
 		matrix<int> for_a(3),for_b(3),for_c(3);
 		for_a.val = {{1,hell,hell},
 			     {0,0,hell},
 			     {hell,1,0} 	
 			    };
 		for_b.val = {{0,hell,hell},
 			     {1,1,hell},
 			     {hell,0,0}
 			    };
 		for_c.val = {{0,hell,hell},
 			     {1,0,hell},
 			     {hell,1,1}	
 			    };
 		string s; cin >> s;
 		for(int i = 1; i <= n; i++){
 			if(s[i - 1] == 'a')seg.upd(n - i + 1,n - i + 1,for_a);
 			else if(s[i - 1] == 'b')seg.upd(n - i + 1,n - i + 1,for_b);
 			else if(s[i - 1] == 'c')seg.upd(n - i + 1,n - i + 1,for_c);
 		}

 		auto calc = [&](){
 			matrix<int> mat = seg.t[1].dp;
 			int ans = n + 1;
 			for(int j = 0; j <= 2; j++){
 				mins(ans,mat.val[j][0]);
 			}
 			return ans;
 		};
 		rep(i,0,q){
 			int j; cin >> j;
 			char c; cin >> c;
 			if(c == 'a')seg.upd(n - j + 1,n - j + 1,for_a);
 			else if(c == 'b')seg.upd(n - j + 1,n - j + 1,for_b);
 			else if(c == 'c')seg.upd(n - j + 1,n - j + 1,for_c);
 			cout << calc() << endl;
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