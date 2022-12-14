#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<=n;i++)
    {
        int x=(n-i);
        if (x%2)continue;
        if ((x/2+i)%m==0)
        {
            cout<<x/2+i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}