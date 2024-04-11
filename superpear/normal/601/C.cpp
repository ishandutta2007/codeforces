#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define w1 first
#define w2 second
#define p_b push_back
#define l_b lower_bound
#define m_p make_pair

const int maxlongint=2147483647;
const int biglongint=2139062143;

int N,M,sm2;
int a[105];
long double dp[105][100005],sm[105][100005];
int lc;

int main()
{
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);

    scanf("%d %d",&N,&M);
    sm2=0;
    for (int i=1;i<=N;i++)
    {
        scanf("%d",&a[i]);
        sm2+=a[i];
    }
    dp[0][0]=1;
    for (int i=0;i<=M*N;i++) sm[0][i]=1;
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=sm2;j++)
        {
            lc=j-M;
            if (lc>0) dp[i][j]=(sm[i-1][j-1]-sm[i-1][lc-1]); else dp[i][j]=sm[i-1][j-1];
            if (j>=a[i]) dp[i][j]-=dp[i-1][j-a[i]];
            dp[i][j]/=double(M-1);
        }
        sm[i][0]=dp[i][0];
        for (int j=1;j<=sm2;j++) sm[i][j]=sm[i][j-1]+dp[i][j];
    }
    long double ans=0;
    for (int i=1;i<sm2;i++) ans+=dp[N][i];
    ans=1+ans*(M-1);
    if (M==1) ans=1;
    printf("%.10lf\n",double(ans));

    return 0;
}