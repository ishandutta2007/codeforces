#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int ss=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        ss+=a[i];
    }
    int sss=0,ans=0;
    for (int i=1; i<n; i++)
    {
        sss+=a[i];
        if (sss*2==ss) ans++;
    }
    cout<<ans<<endl;
}