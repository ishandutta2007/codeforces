#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n,c,a,b;
    cin>>c>>a>>b;
    cin>>n;
    int ans=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (x>a && x<b)
            ans++;
    }
    cout<<ans<<endl;
}