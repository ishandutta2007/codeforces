
#include <bits/stdc++.h>
using namespace std;
int num[1001];
int id[1001];
int main()
{
    int b,d;
    string a,c;
    cin>>b>>d;
    cin>>a>>c;
    int n=a.size(),m=c.size();
    for (int i=0;i<=m;i++)
    {
        int cur=i-1;
        for (int j=0;j<n;j++)
        {
            if (cur==m-1)
            {
                cur=-1;
                num[i]++;
            }
            if (a[j]==c[cur+1])
                cur++;
        }
        if (cur==m-1)
        {
            cur=-1;
            num[i]++;
        }
        id[i]=cur;
    }
    long long ans=0;
    int cur=-1;
    for (int i=0;i<b;i++)
    {
        ans+=num[cur+1];
        cur=id[cur+1];
    }
    cout<<ans/d<<endl;
}