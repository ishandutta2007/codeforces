#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int res=INT_MAX;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (l!=0&&l<=k)
        {
            res=min(res,abs(i-m));
        }
    }
    cout<<res*10<<endl;
}