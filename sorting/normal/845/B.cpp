#include<iostream>

using namespace std;

bool dp[10][10][10][10][10][10][6],b[10][10][10][10][10][10][6];

bool check(int y[])
{
    int i,sum=0;

    for(i=0;i<3;i++)
    {
        sum+=y[i];
    }
    for(i=3;i<6;i++)
    {
        sum-=y[i];
    }

    if(sum==0)return 1;
    return 0;
}

int solve(int y[],int steps)
{
    int i,j,p;

    //cout<<steps<<endl;

    if(check(y))return 1;
    if(steps==0)return 0;
    if(b[y[0]][y[1]][y[2]][y[3]][y[4]][y[5]][steps])return dp[y[0]][y[1]][y[2]][y[3]][y[4]][y[5]][steps];

    //b[y[0]][y[1]][y[2]][y[3]][y[4]][y[5]][steps]=1;

    for(i=0;i<6;i++)
    {
        p=y[i];
        for(j=0;j<10;j++)
        {
            y[i]=j;
            if(solve(y,steps-1))
            {
                return dp[y[0]][y[1]][y[2]][y[3]][y[4]][y[5]][steps]=1;
            }
        }
        y[i]=p;
    }

    return dp[y[0]][y[1]][y[2]][y[3]][y[4]][y[5]][steps]=0;
}

int main ()
{
    int i,y[6];
    string x;

    cin>>x;

    for(i=0;i<6;i++)y[i]=(int)x[i]-'0';

    //cout<<check(y)<<endl;

    for(i=0;true;i++)
    {
        if(solve(y,i))
        {
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}