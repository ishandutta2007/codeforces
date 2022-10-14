#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
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
template<int mod>
struct mint {
  int x;
  mint():x(0){}
  mint(int x):x((x%mod+mod)%mod){}
  // mint(int x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
  friend istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
  friend ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
  mint<mod> expo(mint<mod> x,int y){
       mint<mod> a=1;
       while(y){
       	 if(y&1)a=a*x;
       	 x=x*x;
       	 y/=2;
       }
       return a;
  }
};
template<int mod>
int operator+=(int& b,mint<mod> a){return b=b+a.x;};
template<typename T>
class matrix{
    public:
    vector<vector<T>> val;
    int n;
    matrix<T>(int size){
        n=size;
        val.resize(n);
        rep3(n)val[i].resize(n);
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

int solve(){
 int n;mint<hell>f1,f2,f3,c;
 cin>>n>>f1>>f2>>f3>>c;
 if(n==4){
 	cout<<f1*f2*f3*c*c<<endl;
 	return 0;
 }
 mint<hell> h1=f1*c,h2=f2*c*c,h3=f3*c*c*c;
 matrix<mint<hell-1>> m(3);
 m.val[0][0]=m.val[0][1]=m.val[0][2]=1;
 m.val[1][0]=m.val[2][1]=1;
 m=m.matexpo(m,n-4);
 int p1=0,p2=0,p3=0;
 p1+=m.val[0][0];
 p2+=m.val[0][0]+m.val[0][2];
 p3+=m.val[0][0]+m.val[0][1];
 //cout<<p1<<" "<<p2<<" "<<p3<<endl;
 mint<hell> ans=ans.expo(h1,p1)*ans.expo(h2,p2)*ans.expo(h3,p3);
 n=n%(hell-1);
 ans=ans*ans.expo(c,hell-1-n);
 cout<<ans<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef sieve
    sieve();
    #endif
    #ifdef ncr
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}