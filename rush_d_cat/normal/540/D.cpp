#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef __int64 ll;
const int INF=100000000;
double dp[102][102][102];
int main()
{
    int R,S,P;cin>>R>>S>>P;
    for(int r=0;r<=100;r++)
    {
        for(int s=0;s<=100;s++)
        {
            for(int p=0;p<=100;p++)
            {
                if(r==0) dp[r][s][p]=0;
                else if(s==0&&p!=0) dp[r][s][p]=0;
                else if(s==0&&p==0) dp[r][s][p]=1;
                else if(p==0) dp[r][s][p]=1;
                else
                {
                    int tmp = (r+s+p)*(r+s+p-1)/2;
                    double k1 = (double)(r*s)/tmp;
                    double k2 = (double)(s*p)/tmp;
                    double k3 = (double)(r*p)/tmp;
                    dp[r][s][p] = (dp[r][s-1][p]*k1 + dp[r][s][p-1]*k2 + dp[r-1][s][p]*k3)/(k1+k2+k3);
                }
            }
        }
    }
    printf("%.10lf %.10lf %.10lf\n",dp[R][S][P],dp[S][P][R],dp[P][R][S]);
    return 0;
}