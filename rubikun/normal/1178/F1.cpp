#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=503,INF=1<<30;
int minipos[MAX][MAX];
ll memo[MAX][MAX];

ll solve(int left,int right){
    if(left>=right) return 1;
    if(memo[left][right]) return memo[left][right];
    
    ll a=0,b=0;
    
    for(int i=left;i<=minipos[left][right];i++){
        a+=solve(left,i-1)*solve(i,minipos[left][right]-1);
        a%=mod;
    }
    
    for(int i=minipos[left][right]+1;i<=right+1;i++){
        b+=solve(minipos[left][right]+1,i-1)*solve(i,right);
        b%=mod;
    }
    
    return memo[left][right]=a*b%mod;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            int mini=INF,pos=-1;
            for(int k=i;k<=j;k++){
                if(A[k]<mini){
                    mini=A[k];
                    pos=k;
                }
            }
            minipos[i][j]=pos;
        }
    }
    
    cout<<solve(0,N-1)<<endl;
}