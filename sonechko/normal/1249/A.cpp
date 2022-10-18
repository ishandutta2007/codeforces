#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[N],d[N],use[N],last[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        int ans=1;
        for (int i=2; i<=n; i++)
            if (abs(a[i]-a[i-1])==1) ans=0;
        if (ans==1) cout<<1<<"\n"; else cout<<2<<"\n";
    }
}