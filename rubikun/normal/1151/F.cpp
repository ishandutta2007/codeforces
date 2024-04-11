#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

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
    
    ll N,K;cin>>N>>K;
    vector<ll> A(N);
    int x=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==0) x++;
    }
    
    int a=0;
    
    for(int i=0;i<x;i++) if(A[i]==1) a++;
    
    int y=N-x;
    
    int b=min(x,y);
    
    mat S(b+1,vector<ll>(b+1));
    
    for(int i=0;i<=b;i++){
        S[i][i]=1;
        if(i!=b){
            S[i+1][i]=(x-i)*(y-i)*rui(N*(N-1)/2,mod-2)%mod;
            S[i][i]+=mod-S[i+1][i];
        }
        if(i!=0){
            S[i-1][i]=i*i*rui(N*(N-1)/2,mod-2)%mod;
            S[i][i]+=mod-S[i-1][i];
        }
        
        S[i][i]%=mod;
    }
    
    /*for(int i=0;i<=b;i++){
        for(int j=0;j<=b;j++){
            cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    S=pow(S,K);
    
    mat T(b+1,vector<ll>(1));
    T[a][0]=1;
    
    mat P=mul(S,T);
    
    cout<<P[0][0]<<endl;
    
    
}