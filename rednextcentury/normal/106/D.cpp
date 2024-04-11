
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<stdio.h>
# include <vector>
#define EPS 1e-9
using namespace std;
char a[1001][1001];
int N[1001][1001];
int S[1001][1001];
int W[1001][1001];
int E[1001][1001];
int k;
int num[1000000];
char typ[1000000];
    int n,m;
    vector<char> ret;
bool ok(int x,int y)
{
    for (int i=0;i<k;i++)
    {
        if (typ[i]=='N')
        {
            if (x-num[i]>N[x][y])
                x=x-num[i];
            else
                return 0;
        }
        else if (typ[i]=='S')
        {
            if (x+num[i]<S[x][y])
                x=x+num[i];
            else
                return 0;
        }
        else if (typ[i]=='W')
        {
            if (y-num[i]>W[x][y])
                y=y-num[i];
            else
                return 0;
        }
        else
        {
            if (y+num[i]<E[x][y])
                y=y+num[i];
            else
                return 0;
        }
    }
    return 1;
}
int main()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    for (int i=0;i<n;i++)
    {
        int mx=-1;
        for (int j=0;j<m;j++)
        {
            if (a[i][j]=='#')
                mx=j;
            W[i][j]=mx;
        }
    }
    for (int i=0;i<n;i++)
    {
        int mx=m;
        for (int j=m-1;j>=0;j--)
        {
            if (a[i][j]=='#')
                mx=j;
            E[i][j]=mx;
        }
    }
    for (int i=0;i<m;i++)
    {
        int mx=-1;
        for (int j=0;j<n;j++)
        {
            if (a[j][i]=='#')
                mx=j;
            N[j][i]=mx;
        }
    }
    for (int i=0;i<m;i++)
    {
        int mx=n;
        for (int j=n-1;j>=0;j--)
        {
            if (a[j][i]=='#')
                mx=j;
            S[j][i]=mx;
        }
    }
    cin>>k;
    int ans=0;
    for (int i=0;i<k;i++)
    {
        cin>>typ[i]>>num[i];
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (a[i][j]>='A' && a[i][j]<='Z')
                if (ok(i,j))
                    ret.push_back(a[i][j]);
        }
    }
    if (ret.size()==0)
    {
        cout<<"no solution"<<endl;
        return 0;
    }
    sort(ret.begin(),ret.end());
    for (int i=0;i<ret.size();i++)
    {
        cout<<ret[i];
    }
    cout<<endl;
}