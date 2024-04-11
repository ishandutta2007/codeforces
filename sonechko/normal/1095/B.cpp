#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

const int N = 2e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int mini=1,maxi=1;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]<a[mini]) mini=i;
        if (a[i]>a[maxi]) maxi=i;
    }
    int mini1=2e9,maxi1=-2e9,mini2=2e9,maxi2=-2e9;
    for (int i=1; i<=n; i++)
    {
        if (i!=mini)
        {
            mini1=min(mini1,a[i]);
            maxi1=max(maxi1,a[i]);
        }
        if (i!=maxi)
        {
            mini2=min(mini2,a[i]);
            maxi2=max(maxi2,a[i]);
        }
    }
    cout<<min(maxi1-mini1,maxi2-mini2);
}