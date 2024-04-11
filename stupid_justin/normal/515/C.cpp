#include<bits/stdc++.h>
using namespace std;
int num[10][5];
int cnt[10][5];
int n;
string str;
int sum[10];
signed main()
{
    num[2][1]=1;
    num[3][2]=1;
    num[4][1]=2;
    num[5][3]=1;
    num[6][1]=1;num[6][2]=1;
    num[7][4]=1;
    num[8][1]=3;
    num[9][2]=2;
    for (int i=2;i<=9;i++)
        for (int j=1;j<=4;j++)
            cnt[i][j]=cnt[i-1][j]+num[i][j];
    cin>>n;
    for (int i=1;i<=4;i++) sum[i]=0;
    cin>>str;
    int len=str.length();
    for (int i=0;i<len;i++)
    {
        int t=str[i]-'0';
        for (int j=1;j<=4;j++)
            sum[j]+=cnt[t][j];
    }
    for (int i=1;i<=sum[4];i++) cout<<7,sum[3]-=cnt[7][3],sum[2]-=cnt[7][2],sum[1]-=cnt[7][1];
    for (int i=1;i<=sum[3];i++) cout<<5,sum[2]-=cnt[5][2],sum[1]-=cnt[5][1];
    for (int i=1;i<=sum[2];i++) cout<<3,sum[1]-=cnt[3][1];
    for (int i=1;i<=sum[1];i++) cout<<2;
}