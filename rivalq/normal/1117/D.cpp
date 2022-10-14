//https://codeforces.com/problemset/problem/1117/D
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
class matrix{
    public:
    vector<vector<ll>> val;
    int n;
    matrix(int size){
        n=size;
        val.resize(n);
        rep3(n)val[i].resize(n);
    }
    matrix operator+(const matrix&) const;
    matrix operator-(const matrix&) const;
    matrix operator*(const matrix&) const;
    matrix& operator=(const matrix& b){
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
    matrix mul(int a){
        matrix ans(this->n);
        rep(i,0,this->n){
            rep(j,0,this->n){
                ans.val[i][j]=a*this->val[i][j];
            }
        }
        return ans;
    }

};
matrix matrix::operator+(const matrix& b) const{
    matrix ans(b.n);
    rep(i,0,b.n){
        rep(j,0,b.n){
            ans.val[i][j]=this->val[i][j]+b.val[i][j];
        }
    }
    return ans;
}
matrix matrix::operator-(const matrix& b) const{
    matrix ans(b.n);
    rep(i,0,b.n){
        rep(j,0,b.n){
            ans.val[i][j]=this->val[i][j]-b.val[i][j];
        }
    }
    return ans;
}
matrix matrix::operator*(const matrix& b) const{
    matrix ans(b.n);
    rep(i,0,b.n){
        rep(j,0,b.n){
            rep(k,0,b.n){
                ans.val[i][j]=(ans.val[i][j]+this->val[i][k]*b.val[k][j]%hell)%hell;
            }
        }
    }
    return ans;			
}
matrix identity(int N){
    matrix ans(N);
    rep(i,0,N){
        ans.val[i][i]=1;
    }
    return ans;
}
matrix matexpo(matrix a, ll n){
    if(n==0){
        return identity(a.n);
    }
    if(n==1) return a;
    matrix x=matexpo(a,n/2);
    matrix r=x*x;
    if(n&1) r=r*a;
    return r;
}
int solve(){
 ll n,m;cin>>n>>m;           
 if(n<=m){
     if(n==m)cout<<2<<endl;
     else cout<<1<<endl;
     ret;
 }           
 matrix mat(m);
 mat.set(0);
 mat.val[0][0]=mat.val[0][m-1]=mat.val[1][0]=1;
 for(int i=1;i<m;i++)mat.val[i][i-1]=1;
 //mat.print();
 mat=matexpo(mat,n-m+1);
 ll ans=0;
 for(int i=0;i<m;i++)ans=(ans+mat.val[0][i])%hell;
 cout<<ans<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}