#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_7 (ll)(1E6+3)
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;

#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
///////////////////////////////////////

#define N (ll)1E6+3

ll po(ll i,ll p){
    if(p==0)return 1;
    else if(p==1)return mod(i);
    else if(p%2==0)return po(mod(mod(i)*mod(i)),p/2);
    else  return mod(mod(i)*po(i,p-1));
}

ll bunbo[N];
void cal(){
    rep(i,0,N-1)bunbo[i]=po(i,i_5);
}

typedef vector<ll>vec;
typedef vector<vec> mat;

//Ax=b A
//0
vec gauss_jordan(const mat& A,const vec &b){
    ll n=A.size();
    mat B(n,vec(n+1));
    rep(i,0,n-1)rep(j,0,n-1)B[i][j]=A[i][j];
    //Ab
    rep(i,0,n-1)B[i][n]=b[i];
    
    rep(i,0,n-1){
        //i
        ll pivot=i;
        rep(j,i,n-1){
            if(abs(B[j][i])>abs(B[pivot][i]))pivot=j;
        }
        swap(B[i],B[pivot]);
        //
        if(abs(B[i][i])<EPS)return vec();
        //1
        //rep(j,i+1,n)B[i][j]/=B[i][i];
        rep(j,i+1,n)B[i][j]=mod(B[i][j]*bunbo[B[i][i]]);
        rep(j,0,n-1){
            if(i!=j){
                //rep(k,i+1,n)B[j][k]-=B[j][i]*B[i][k];
                rep(k,i+1,n)B[j][k]=mod(B[j][k]-B[j][i]*B[i][k]);
            }
        }
    }
    vec x(n);
    rep(i,0,n-1)x[i]=mod(B[i][n]);
    return x;
}
//////////////////////////////////////////

#define M 11

int main(){fastio
    cal();
    mat a(M,vec(M));
    rep(i,0,M-1){
        a[i][0]=1;
        rep(j,1,M-1){
            a[i][j]=mod(a[i][j-1]*i);
        }
    }
    vec b(M);
    rep(i,0,M-1){
        cout<<"? "<<i<<endl;
        fflush(stdout);
        cin>>b[i];
    }
    vec x(M);
    x=gauss_jordan(a,b);
    //rep(i,0,M-1)cout<<x[i]<<" ";
    
    rep(i,0,N-1){
        ll sum=0;
        rep(j,0,M-1){
            Add(sum,x[j]*po(i,j));
        }
        if(mod(sum)==0){
            cout<<"! "<<i<<endl;
            fflush(stdout);
            return 0;
        }
    }
    cout<<"! -1"<<endl;
    
    return 0;
}