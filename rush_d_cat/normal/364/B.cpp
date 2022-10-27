#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N=52;
int n,d;
int c[N],sum[N];
int dp[N][N*10000];
vector<int> v;

int main(){
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    dp[0][0]=1;
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=sum;j++){
            dp[i+1][j]|=dp[i][j];
            dp[i+1][j+c[i+1]]|=dp[i][j];
        }
        sum+=c[i+1];
    }
    for(int i=0;i<=sum;i++)if(dp[n][i])v.push_back(i);
    int now=0,ans=0;
    while(1){
        int nex=v[upper_bound(v.begin(),v.end(),now+d)-v.begin()-1];
        if(now==nex)break;
        now=nex;ans++;
    }
    cout<<now<<" "<<ans<<endl;
}