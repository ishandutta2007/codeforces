#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debug puts("isok")
using namespace std;

double dp[2][100005],sum[100005];
int n,m,r[1005],k,now;

int main(){
    scanf("%d%d",&n,&m);
    if(m==1){puts("1");return 0;}
    for(int i=1;i<=n;i++)
        scanf("%d",&r[i]),now+=r[i];
    dp[0][0]=m-1;k=0;
    for(int i=1;i<=n;i++){
        sum[0]=0.0;
        for(int j=0;j<=i*m;j++) sum[j+1]=sum[j]+dp[k][j];
        k^=1;
//      dp[k][0]=0;
        for(int j=0;j<=i*m;j++)
            dp[k][j]=(sum[j]-sum[max(0,j-m)]-(j>=r[i]?dp[k^1][j-r[i]]:0))/(double)(m-1);
    }
    double ans=0;
    for(int i=0;i<now;i++) ans+=dp[k][i];
    printf("%.13f\n",ans+1);
    return 0;
}