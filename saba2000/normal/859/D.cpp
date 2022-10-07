#include<bits/stdc++.h>
using namespace std;
double dp[100][100];
double P1[100][100];
double P[100][100];
main()
{
    int n;
    cin>>n;
    int N=(1<<n);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
       {cin>>P[i][j];
        P[i][j]/=(double)100;}
        for (int i=0; i<N; i++)
            P1[0][i]=1.0;
        for (int i=1; i<=n; i++)
        for (int j=0; j<=N; j++)
        P1[i][j]=0.0;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<(1<<(n-i+1)); j+=2)
        {
            int a=j*(1<<(i-1)),b=(j+1)*(1<<(i-1))-1;
            int p=(j+1)*(1<<(i-1)),q=(j+2)*(1<<(i-1))-1;
            for (int k=a; k<=b; k++)
            for (int m=p; m<=q; m++){
                    //cout<<i<<" "<<k<<" "<<m<<"   "<<P1[2][7]<<" "<<P1[i][k]<<endl;
                    double c=P1[i-1][k]*P1[i-1][m];
            // dp[i][k]=max( dp[i][k],((dp[i-1][k]+dp[i-1][m])+(1<<(i-1)))*P[k][m]*P1[i-1][k]*P1[i-1][m]);
             //       +(dp[i-1][k]+dp[i-1][m])*P[m][]
                     //           cout<<P1[i][k]<<" "<<P1[i][k]+P1[i-1][k]*P[k][m]endl;
                  //   cout<<i<<"  "<<m<<" "<<P1[i][m]<<endl;
                  double d=P1[i][k]+c*P[k][m];
                 // cout<<d<<" "<<i<<" "<<k<<endl;
            P1[(int)i][k]=d;
           //  cout<<i<<" "<<k<<" "<<m<<"   "<<P1[3][7]<<" "<<P1[i][k]<<endl;
           //  cout<<i-1<<" "<<m<<" "<<P1[i-1][m]<<endl;
//cout<<i<<" "<<k<<" "<<P1[i-1][k]*P[k][m]*P1[i-1][m]<<endl;
           // cout<<P1[i][k]<<endl;
           // cout<<P1[i][k]<<" "<<P1[i-1][k]*P[k][m]<<endl;
            P1[i][m]=P1[i][m]+c*P[m][k];
            // cout<<i<<" "<<k<<" "<<m<<"   "<<P1[2][7]<<endl;
            //cout<<P1[i-1][k]<<" "<<P[m][k]<<" "<<P1[i-1][m]<<" "<<P1[i-1][k]*P[m][k]*P1[i-1][m]<<endl;
          //  cout<<i<<" "<<m<<" "<<P1[i-1][k]*P[m][k]*P1[i-1][m]<<endl;
          }
 for (int k=a; k<=b; k++)
            for (int m=p; m<=q; m++)
            dp[i][k]=max(dp[i][k],dp[i-1][k]+dp[i-1][m]+(1<<(i-1))*P1[i][k]);

        for (int k=p; k<=q; k++)
            for (int m=a; m<=b; m++)
            dp[i][k]=max(dp[i][k],dp[i-1][k]+dp[i-1][m]+(1<<(i-1))*P1[i][k]);


        }
        //cout<<endl;
  //  for (int j=0; j<N; j++)
          // cout<<i<<" "<<j<<" "<<P1[i][j]<<endl;
    }
    double ans=0;
    for(int i=0; i<N; i++)
        ans=max(ans,dp[n][i]);
        printf("%.10f",ans);

}
//1 2   3 4  5 6  7 8
//   1 2 3 4  5 6 7 8