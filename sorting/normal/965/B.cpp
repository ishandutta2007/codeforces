#include<iostream>

using namespace std;

string s[101];
int a[101][101];
int res[101][101];

int main ()
{
    int n,k,i,j,sum,maxi=-1,x,y;

    cin>>n>>k;

    for(i=0;i<n;i++)
        cin>>s[i];

    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<k;j++)
            if(s[i][j]=='#')
                sum++;
        if(sum==0)
            a[i][0]=1;
        for(j=k;j<n;j++)
        {
            if(s[i][j-k]=='#')
                sum--;
            if(s[i][j]=='#')
                sum++;
            if(sum==0)
                a[i][j-k+1]=1;
        }
    }

    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<k;j++)
        {
            if(a[i][j]==1)
                sum++;
            res[i][j]+=sum;
        }
        for(j=k;j<n;j++)
        {
            if(a[i][j-k]==1)
                sum--;
            if(a[i][j]==1)
                sum++;
            res[i][j]+=sum;
        }
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]=0;

    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<k;j++)
            if(s[j][i]=='#')
                sum++;
        if(sum==0)
            a[0][i]=1;
        for(j=k;j<n;j++)
        {
            if(s[j-k][i]=='#')
                sum--;
            if(s[j][i]=='#')
                sum++;
            if(sum==0)
                a[j-k+1][i]=1;
        }
    }

    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<k;j++)
        {
            if(a[j][i]==1)
                sum++;
            res[j][i]+=sum;
        }
        for(j=k;j<n;j++)
        {
            if(a[j-k][i]==1)
                sum--;
            if(a[j][i]==1)
                sum++;
            res[j][i]+=sum;
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(res[i][j]>maxi)
            {
                maxi=res[i][j];
                x=i+1;
                y=j+1;
            }
    }

    cout<<x<<" "<<y<<endl;

    return 0;
}