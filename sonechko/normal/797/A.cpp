#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 17;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int k1=0;
    for (int d=2; d<=n; d++)
    {
        while (n%d==0)
        {
            if (k1<m) {k1++; a[k1]=d;} else
                a[1]*=d;
            n/=d;
        }
    }
    if (k1<m) cout<<-1<<endl; else
    {
        for (int i=1; i<=m; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }

}