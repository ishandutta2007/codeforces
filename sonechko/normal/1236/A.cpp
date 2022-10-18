#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int ans=0;
        for (int k=0; k<=min(a,b/2); k++)
        {
            int bb=b-k*2;
            ans=max(ans,k+min(bb,c/2));
        }
        cout<<ans*3<<"\n";
    }
}