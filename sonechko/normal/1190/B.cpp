#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
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
    sort(a+1,a+n+1);
    if (a[n]==0||(a[2]==0&&n>=2)) {cout<<"cslnb"; return 0;}
    vector<int> vv;
    for (int i=2; i<=n; i++)
        if (a[i]==a[i-1]) vv.pb(i);
    if (vv.size()>1) {cout<<"cslnb"; return 0;}
    if (vv.size()==1)
    {
        int l=vv[0];
        if (l>2&&a[l]-1==a[l-2]) {cout<<"cslnb"; return 0;}
        a[l]--;
        sort(a+1,a+n+1);
        int ans=0;
        for (int i=1; i<=n; i++)
            ans=(ans+(a[i]-(i-1)))%2;
        if (ans%2==1) {cout<<"cslnb"; return 0;}
        else {cout<<"sjfnb"; return 0;}
    } else
    {
        int ans=0;
        for (int i=1; i<=n; i++)
            ans=(ans+(a[i]-(i-1)))%2;
        if (ans%2==0) {cout<<"cslnb"; return 0;}
        else {cout<<"sjfnb"; return 0;}
    }
}