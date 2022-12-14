#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int b[1000000];
int loc[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        loc[a[i]]=i;
    }
    for (int i=1;i<=n;i++) {
        cin >> b[i];
        b[i]=loc[b[i]];
    }
    int mn=1e9;
    int ret=0;
    for (int i=n;i>=1;i--)
    {
        if (mn<b[i])ret++;
        mn=min(mn,b[i]);
    }
    cout<<ret<<endl;
}