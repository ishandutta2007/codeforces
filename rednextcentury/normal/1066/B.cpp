#include <bits/stdc++.h>
using namespace std;
int r;
int ret=0;
int a[10001];
int n;
bool ok=1;
void cover(int x)
{
    if (x>=n)return;
    for (int i=x+r-1;i>=x-r+1;i--)
    {
        if (i<0)break;
        if (a[i]==1)
        {
            ret++;
            cover(i+r);
            return;
        }
    }
    ok=0;
}
int mod=998244353;
int main()
{
    cin>>n>>r;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cover(0);
    if (!ok)cout<<-1<<endl;
    else cout<<ret<<endl;
}