#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int mod=1000000007,mod2=1000000006,MAX=100005,INF=1<<30;
typedef vector<vector<ll>> mat;

mat mul(mat &A, mat&B){
    mat C(A.size(),vector<ll>(B[0].size()));
    for(int i=0;i<A.size();i++){
        for(int k=0;k<B.size();k++){
            for(int j=0;j<B[0].size();j++){
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod2;
            }
        }
    }
    return C;
}

mat pow(mat A,ll n){
    mat B(A.size(),vector<ll>(A.size()));
    for(int i=0;i<A.size();i++){
        B[i][i]=1;
    }
    
    while(n>0){
        if(n&(1LL)) B=mul(B,A);
        A=mul(A,A);
        n/=2;
    }
    return B;
}

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,x,y,z,c;cin>>N>>x>>y>>z>>c;
    ll ans=1;
    
    mat A(3,vector<ll>(3)),B(3,vector<ll>(1)),C;
    A[0][0]=A[0][1]=A[0][2]=A[1][0]=A[2][1]=1;
    B[0][0]=1;
    A=pow(A,N-3);
    C=mul(A,B);
    ans*=rui(z,C[0][0]);
    ans%=mod;
    swap(B[0][0],B[1][0]);
    C=mul(A,B);
    ans*=rui(y,C[0][0]);
    ans%=mod;
    swap(B[1][0],B[2][0]);
    C=mul(A,B);
    ans*=rui(x,C[0][0]);
    ans%=mod;
    
    mat D(5,vector<ll>(5)),E(5,vector<ll>(1));
    D[0][0]=D[0][1]=D[0][2]=D[1][0]=D[2][1]=D[3][3]=D[3][4]=D[4][4]=1;
    D[0][3]=2;
    
    E[3][0]=E[4][0]=1;
    
    D=pow(D,N-3);
    
    D=mul(D,E);
    
    ans*=rui(c,D[0][0]);
    ans%=mod;
    
    cout<<ans<<endl;
}