#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200001,INF=1LL<<55;
typedef vector<ll> vec;
typedef vector<vec> mat;

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
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll N,M;cin>>N>>M;
    mat A(M,vec(M)),B(M,vec(1,1));
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            if(i==0&&j==0) A[i][j]=1;
            else if(i==0&&j==M-1) A[i][j]=1;
            else if(i-j==1) A[i][j]=1;
            else A[i][j]=0;
        }
    }
    A=pow(A,N);
    mat C(M,vec(1));
    C=mul(A,B);
    cout<<C[M-1][0]<<endl;
}