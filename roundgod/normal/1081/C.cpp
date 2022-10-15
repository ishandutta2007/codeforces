#include<bits/stdc++.h>
#define maxn 2050
using namespace std;
typedef long long ll;
const int M=998244353;
int C[maxn][maxn],n,m,k;
ll ans;

int main(){
    for (int i=0;i<maxn;i++){
        C[i][0]=C[i][i]=1;
        for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
    }
    cin >> n >> m >> k; k=n-1-k;
    ans=C[n-1][k]; n-=k;
    ans=ans*m%M;
    for (int i=1;i<n;i++) ans=ans*(m-1)%M;
    cout << ans << endl;
}