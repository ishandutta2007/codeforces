#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=200001,INF=1<<30;

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

typedef vector<vector<ll>> mat;

mat mul(mat &A, mat&B){
    mat C(A.size(),vector<ll>(B[0].size()));
    for(int i=0;i<A.size();i++){
        for(int k=0;k<B.size();k++){
            for(int j=0;j<B[0].size();j++){
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod;
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
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n/=2;
    }
    return B;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll H,W,L,R;cin>>H>>W>>L>>R;
    if((H*W)%2){
        cout<<rui(R-L+1,H*W)<<endl;
    }else{
        ll a=R/2-(L-1)/2,b=(R-L+1)-a;
        mat A(2,vector<ll>(2)),B(2,vector<ll>(1));
        
        A[0][0]=A[1][1]=(a*a+b*b)%mod;
        A[0][1]=A[1][0]=2*a*b%mod;
        
        B[0][0]=1;
        
        A=pow(A,(H*W)/2);
        A=mul(A,B);
        cout<<A[0][0]<<endl;
    }
}