#include <bits/stdc++.h>
using namespace std;
long long ret=0;
int n,m;
long long k;
long long a[1000][1000];
map<long long,int> v[1001][1001];
void BF1(int i,int j,int len,long long val)
{
    if (len==0)
        v[i][j][val]++;
    else
    {
        if (i+1<n)BF1(i+1,j,len-1,val^a[i][j]);
        if (j+1<m)BF1(i,j+1,len-1,val^a[i][j]);
    }
}

void BF2(int i,int j,int len,long long val)
{
    if (len==0)
    {
        val=val^a[i][j];
        val=val^k;
        if (v[i][j].count(val))
            ret+=v[i][j][val];
    }
    else
    {
        if (i-1>=0)BF2(i-1,j,len-1,val^a[i][j]);
        if (j-1>=0)BF2(i,j-1,len-1,val^a[i][j]);
    }
}
int main()
{
    cin>>n>>m>>k;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    int len = n+m-2;
    BF1(0,0,len/2,0);
    BF2(n-1,m-1,len/2+len%2,0);
    cout<<ret<<endl;
}