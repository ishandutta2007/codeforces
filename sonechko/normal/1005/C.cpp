#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 5e5 + 11;
const int MOD = 1e9 + 7;

int a[N];
map<int,int> mt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        mt[a[i]]++;
    }
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int d=0;
        for (int j=1; j<=30; j++)
            if (mt[(1<<j)-a[i]]>1) d=1; else
            if (mt[(1<<j)-a[i]]==1&&a[i]*2!=(1<<j)) d=1;
        if (d==0) ans++;
    }
    cout<<ans<<endl;
}