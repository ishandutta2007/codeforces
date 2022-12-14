#include <bits/stdc++.h>
using namespace std;
bool vis[10000000];
int MX=10000000;
int main()
{
    int n,m;
    cin>>n>>m;
    int n2=0,n3=0,b=0;
    if (n+m==0)
    {
        cout<<0<<endl;
        return 0;
    }
    for (int i=2;i<=MX;i++)
    {
        if (i%2==0 && i%3==0) b++;
        else if (i%3==0) n3++;
        else if (i%2==0) n2++;
        int cur=b;
        cur-=max(0,n-n2);
        cur-=max(0,m-n3);
        if (cur>=0)
        {
            cout<<i<<endl;
            return 0;
        }
    }
}