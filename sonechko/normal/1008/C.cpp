#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 3e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int pos=1,ans=0;
    for (int i=1; i<=n; i++)
    {
        while (pos<=n&&a[pos]<=a[i])
            pos++;
        if (pos<=n) {pos++; ans++;}
    }
    cout<<ans<<endl;
}