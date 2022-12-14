#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    b=min(b,n);
    a=min(a,n);
    int ret=0;
    for (int i=0;i<=n;i++)
    {
        if (i<=a && n-i<=b)
            ret++;
    }
    cout<<ret<<endl;

}