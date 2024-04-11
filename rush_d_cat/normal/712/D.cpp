#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;
const int N=420002;
const int M=210000;
int a,b,k,t;
LL dp[102][N];
LL sun[N],sum[N],psum[N],ssum[N];
int main() {
    cin>>a>>b>>k>>t;
    LL ret=0;
    dp[0][M]=1;
    for(int i=1;i<=t;i++){
        int L = M-i*2*k;
        int R = M+i*2*k; 

        for(int j=L;j<=R;j++) 
            sum[j]=(sum[j-1]+dp[i-1][j])%MOD;
        
        for(int j=L;j<=R;j++)
            psum[j]=(psum[j-1]+sum[j])%MOD;

        for(int j=L;j<=R;j++) {

            LL s1, s2;
            if (j+2*k <= R) {
                s1 = psum[j+2*k]-psum[j-1];
            } else {
                s1 = psum[R]-psum[j-1] + (j+2*k-R)*sum[R];
            }

            if (j-2*k-2 >= L) {
                s2 = psum[j-1] - psum[j-2*k-2];
            } else {
                s2 = psum[j-1] - psum[L] + (L-(j-2*k-2))*sum[L];
            }
            dp[i][j]=((s1-s2)%MOD+MOD)%MOD;

            if(i==t && j-M>b-a) ret=(ret+dp[i][j])%MOD;
        }
    }
    cout<<ret<<endl;
}