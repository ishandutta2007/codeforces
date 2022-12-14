# include <iostream>
# include <cmath>
# include <stdio.h>
#include <algorithm>
using namespace std;
int dp1[101][901][10];
int dp2[101][901][10];
void mx(int a[10],int b[10])
{
    for (int i=9;i>=0;i--)
    {

        if (b[i]>a[i])
        {
            for (int x=0;x<10;x++)
                a[x]=b[x];
            return;
        }
        if (a[i]>b[i])
            return;
    }
}
void mn(int a[10],int b[10])
{
    int mna=1,mnb=1;
    while(a[mna]<=0)
        mna++;
    while(b[mnb]<=0)
        mnb++;
    if (mnb<mna)
    {
        for (int x=0;x<10;x++)
                a[x]=b[x];
            return;
    }
    else if (mna<mnb)
        return;
    for (int i=0;i<10;i++)
    {
        if (b[i]>a[i])
        {
            for (int x=0;x<10;x++)
                a[x]=b[x];
            return;
        }
        if (a[i]>b[i])
            break;
    }
}
void printmax(int len,int sum)
{
    for (int i=9;i>=0;i--)
    {
        while(dp1[len][sum][i]>0)
        {
            cout<<i;
            dp1[len][sum][i]--;
        }
    }
}
void printmin(int len,int sum)
{
    for (int i=1;i<=9;i++)
    {
        if (dp2[len][sum][i]>0)
        {
            cout<<i;
            dp2[len][sum][i]--;
            break;
        }
    }
    for (int i=0;i<=9;i++)
    {
        while(dp2[len][sum][i]>0)
        {
            cout<<i;
            dp2[len][sum][i]--;
        }
    }
}
int main ()
{

    for (int x=0;x<=100;x++)
    {
        for (int i=9*x+1;i<=900;i++)
        {


        for (int o=0;o<10;o++)dp2[x][i][o]=-10000;}
    }
    for (int i=0;i<10;i++)
        dp1[1][i][i]=dp2[1][i][i]=1;
    for (int i=2;i<=100;i++)
    {
        for (int x=1;x<=900;x++)
        {
            int best[10]={0};
            for (int j=x;j>=max(0,x-9);j--)
            {
                int now[10]={0};
                for (int o=0;o<10;o++)
                {
                    now[o]+=dp1[i-1][j][o];
                }
                now[x-j]++;
                mx(best,now);
            }
            for (int o=0;o<10;o++)
                dp1[i][x][o]=best[o];
        }
    }
    for (int i=2;i<=100;i++)
    {
        for (int x=1;x<=900;x++)
        {
            int best[10]={0};
            for (int j=x;j>=max(0,x-9);j--)
            {
                int now[10]={0};
                for (int o=0;o<10;o++)
                {
                    now[o]+=dp2[i-1][j][o];
                }
                now[x-j]++;
                mn(best,now);
            }
            for (int o=0;o<10;o++)
                dp2[i][x][o]=best[o];
        }
    }
    int len,sum;
    cin>>len>>sum;
    if (sum==0 && len==1)
        cout<<"0 0"<<endl;
    else if (sum==0 || sum>9*len) cout<<"-1 -1"<<endl;
    else
    {
        printmin(len,sum);
        cout<<" ";
        printmax(len,sum);
        cout<<endl;
    }
}