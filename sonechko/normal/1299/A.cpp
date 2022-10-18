#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 3e5 + 11;

int a[N],kk[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        for (int p=0; p<=30; p++)
            if (a[i]&(1<<p)) kk[p]++;
    }
    int mx=0,pos=1;
    for (int i=1; i<=n; i++)
    {
        int res=0;
        for (int p=0; p<=30; p++)
            if ((a[i]&(1<<p))&&kk[p]==1) res+=(1<<p);
        if (res>mx) {mx=res; pos=i;}
    }
    cout<<a[pos]<<" ";
    for (int i=1; i<=n; i++)
        if (i!=pos) cout<<a[i]<<" ";
}