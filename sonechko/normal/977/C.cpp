#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define ull unsigned long long

const int N = 2e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if (k==0)
    {
        if (a[1]==1) {cout<<-1<<endl; return 0;}
        cout<<1<<endl;
        return 0;
    }
    if (a[k]==a[k+1]) {cout<<-1<<endl; return 0;}
    cout<<a[k]<<endl;
}