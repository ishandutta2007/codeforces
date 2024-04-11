#include<bits/stdc++.h>
using namespace std;

void up()
{
    int n;
    cin>>n;
    int sum=0,ans=0;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        if (x==0) {ans++; x++;}
        sum+=x;
    }
    if (sum==0) ans++;
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}