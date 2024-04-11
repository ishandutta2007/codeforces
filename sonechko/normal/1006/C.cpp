#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int pos=n+1;
    ll s1=0,s3=0;
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        s1+=a[i];
        while (pos>i+1&&s3<s1)
        {
            pos--;
            s3+=a[pos];
        }
        if (s1==s3) ans=s1;
    }
    cout<<ans<<endl;
}