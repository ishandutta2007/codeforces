#include<bits/stdc++.h>
#pragma GCC optimize "trapv"
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
int n,t;
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
                  if(this->val[i][k]>=t || b.val[k][j]>=t)ans.val[i][j]=t;
                  else{
                     int z=this->val[i][k]*b.val[k][j];
                     ans.val[i][j]+=z;
                     if(ans.val[i][j]>=t)ans.val[i][j]=t;
                  }
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
void get(vector<int>&v){
  int n=sz(v);
  int s=0;
  for(int i=0;i<n;i++){
    s+=v[i];
    if(s>=t){
      v[n-1]=t;
      return;
    }
    v[i]=s;
  }
}
bool ch(vector<int>&v,int k){
    int n=sz(v);
    int sum=0;
    for(int i=0;i<n;i++){
      if(v[i]==0)continue;
      int delta=n-i-1;
      int cnt=delta;
      int temp=k+delta;
      int s=v[i];
      int s2=1;
      for(int i=1;i<=delta;++i)s2*=i;
      while(cnt--){
          if(((long double)t/s)*s2<temp)return 1;
          s=s*temp;
          temp--;
         //if(s>=t)return 1;
      }
      s/=s2; 
      if(s>=t)return 1;
      sum=sum+s;
      if(sum>=t)return 1;
    } 
    return sum>=t;
}
int solve(){
 cin>>n>>t;
 vector<int>v;
 for(int i=0;i<n;i++){
  int t;cin>>t;
  v.pb(t);
 }
 reverse(all(v));
 while(v.back()==0)v.pop_back();
 reverse(all(v));
 int s=0;
 for(auto i:v){
    s+=i;
    if(i>=t){
      cout<<0<<endl;return 0;
    }
 }
 if(s>=t){
  cout<<1<<endl;return 0;
 }
 n=sz(v);
 if(n>=4){
    int cnt=0;
    while(v.back()<t){
        get(v);
        cnt++;
    }
    cout<<cnt<<endl;
    //for(int i=0;i<n;i++)cout<<v[i]<<" ";cout<<endl;
    return 0;
 }
 else{
     int lo=1;
     int hi=1e18;
     int ans=0;
     while(lo<=hi){
       int m=(lo+hi)/2;
         if(ch(v,m))ans=m+1,hi=m-1;
         else lo=m+1;
     }
     //cout<<ch(v,0)<<endl;
     cout<<ans<<endl;
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