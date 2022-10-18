#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;

int kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        kol[l]++;
    }
    int ans=0;
    for (int i=1; i<=100; i++)
    {
        kol[i]%=2;
        ans+=kol[i];
        kol[i+1]+=kol[i];
    }
    cout<<ans<<endl;
}