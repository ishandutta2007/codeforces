#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<59;
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
    map<ll,int> MA;
    
    for(ll i=2;i*i<=N;i++){
        while(N%i==0){
            MA[i]++;
            N/=i;
        }
    }
    if(N!=1) MA[N]++;
    ll sum=1;
    
    for(auto it=MA.begin();it!=MA.end();it++){
        ll a=(*it).first,b=(*it).second;
        mat A(b+1,vector<ll>(b+1));
        
        for(int j=0;j<b+1;j++){
            for(int i=0;i<=j;i++){
                A[i][j]=rui(j+1,mod-2);
            }
        }
        
        A=pow(A,K);
        
        mat B(b+1,vector<ll>(1));
        B[b][0]=1;
        
        B=mul(A,B);
        ll kake=0;
        
        for(int i=0;i<b+1;i++){
            kake+=B[i][0]*rui(a,i);
            kake%=mod;
        }
        
        sum*=kake;
        sum%=mod;
    }
    
    cout<<sum<<endl;
}