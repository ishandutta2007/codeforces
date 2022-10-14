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

const int N = 3e5 + 5;
template<typename T>
//#define double long double
class matrix{
    public:
    double val[3][3];
    int n;
    matrix<T>(int size = 3){
    	memset(val,0,sizeof(val));
        n=size;
    }
    matrix<T> operator+(const matrix<T>&) const;
    matrix<T> operator-(const matrix<T>&) const;
    matrix<T>& operator=(const matrix<T>& b){
        for(int i = 0; i < 3; i++){
        	for(int j = 0; j < 3; j++){
        		val[i][j] = b.val[i][j];
        	}
        }
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
        rep(i,0,b.n){
            rep(j,0,b.n){
              rep(k,0,b.n){
                  ans.val[i][j]+=this->val[i][k]*b.val[k][j];
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

struct node{
    matrix<double> a;
    node (int val=0){
        a = a.identity(3);
    }
    void merge(node &n1,node &n2){
         a = n1.a*n2.a;
    }
};
struct update{
  matrix<double> val;
  update(int t=0){
     val = val.identity(3);
  }
  void combine(update &par,int tl,int tr){
      val = par.val*val;
  }
  void apply(node &node){
      node.a = val*node.a;
      val = val.identity(3);
  }
};
template<typename node,typename update>
struct segtree{
  node t[4*N];
  bool lazy[4*N];
  update zaker[4*N];
  int tl[4*N];
  int tr[4*N];
  node nul;
  inline void pushdown(int v){
     if(lazy[v]){    
       apply(zaker[v],v);
       lazy[v]=0;
       zaker[v].apply(t[v]);
     }
  }
  inline void apply(update &u,int v){
      if(tl[v]!=tr[v]){
          lazy[2*v]=lazy[2*v+1]=1;
          zaker[2*v].combine(u,tl[2*v],tr[2*v]);
          zaker[2*v+1].combine(u,tl[2*v+1],tr[2*v+1]);
      }
  }
  void build(int v,int start,int end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a = t[v].a.identity(3);
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,update val){
      pushdown(v);
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].a = val.val*t[v].a;
            apply(val,v); 
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  node query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return nul;
      pushdown(v);
      if(l<=tl[v] && tr[v]<=r){
         return t[v];
      }
      int mid = (tl[v] + tr[v])/2;
      if(r <= mid)return query(2*v,l,r);
      if(l > mid)return query(2*v + 1,l,r);
      node a=query(2*v,l,r);
      node b=query(2*v+1,l,r);
      node ans;
      ans.merge(a,b);
      return ans;
  }
public:
  node query(int l,int r){
      return query(1,l,r);
  }
  void upd(int l,int r,update val){
      return zeno(1,l,r,val);
  }   
};

segtree<node,update> seg;

int solve(){
		int n,m; cin >> n >> m;
		vector<pii> vec(n + 2);
		for(int i = 1; i <= n + 1; i++){
			vec[i] = {i - 1,0};
		} 

		seg.build(1,1,n + 1);

		
		auto cord = [&](int i){
			auto s = seg.query(i,i).a;
			//s.print();
			//cout <<"--\n";
			double x = vec[i].x*s.val[0][0] + vec[i].y*s.val[0][1] + s.val[0][2];
			double y = vec[i].x*s.val[1][0] + vec[i].y*s.val[1][1] + s.val[1][2];
			return make_pair(x,y);
		};
		//0 1 2 3 4 5
		double pi = acos(-1);
		cout << fixed << setprecision(10) << endl;
		while(m--){
			int x,y,z; cin >> x >> y >> z;
			if(x == 1){
				auto [x1,y1] = cord(y);
				auto [x2,y2] = cord(y + 1);
				double theta = 0;
				double dis = sqrt((y1 - y2)*(y1 - y2) + (x1 - x2)*(x1 - x2));
				double dx = z*(x2 - x1)/dis;
				double dy = z*(y2 - y1)/dis;
				matrix<double> mat(3);
				mat = mat.identity(3);
				mat.val[0][2] = dx;
				mat.val[1][2] = dy;
				update upd;
				upd.val = mat;
				seg.upd(y + 1,n + 1,upd);
			}else{
				auto [x1,y1] = cord(y);
				auto [x2,y2] = cord(y + 1); 
				matrix<double> mat(3);
				mat = mat.identity(3);
				mat.val[0][2] = -x1;
				mat.val[1][2] = -y1;
				update upd;upd.val = mat;
				seg.upd(y + 1,n + 1,upd);
				matrix<double> val(3);

				val.val[0][0] = cos(z*pi/180);
				val.val[0][1] = sin(z*pi/180);
				val.val[1][0] = -sin(z*pi/180);
				val.val[1][1] = cos(z*pi/180);
				val.val[2][2] = 1;
				upd.val = val;
				seg.upd(y + 1,n + 1,upd);
				mat.val[0][2] = x1;
				mat.val[1][2] = y1;
				upd.val = mat;
				seg.upd(y + 1,n + 1,upd);
			}
			auto [x2,y2] = cord(n + 1);
			cout << x2 << " " << y2 << endl; 
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