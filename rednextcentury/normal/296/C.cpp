# include <iostream>
# include <string>
# include <map>
# include <stdio.h>
# include <cmath>
# include <cstdio>
# include <queue>
# include <algorithm>
# include <stack>
# include <cstring>
# include <iomanip>
# include<ios>
using namespace std;
long long query[1000000][3];
long long a[1000000];
long long b[1000000];
long long c[1000000];
int main()
{   
    long long n,m,q;
    cin>>n>>m>>q;
    for (long long i=1;i<=n;i++)
    {
       cin>>c[i];
    }
    for (long long i=1;i<=m;i++)
    {
        cin>>query[i][0]>>query[i][1]>>query[i][2];
    }
    for (long long i=0;i<q;i++)
    {
        long long l,r;
        cin>>l>>r;
        b[l]++;
        b[r+1]--;
    }
    long long now=0;
    for (long long i=1;i<=m;i++)
    {
        now+=b[i];
        a[query[i][0]]+=query[i][2]*now;
        a[query[i][1]+1]-=query[i][2]*now;
    }
    now=0;
    for (long long i=1;i<=n;i++)
    {
        now+=a[i];
        cout<<now+c[i]<<" ";
    }
    cout<<endl;
}