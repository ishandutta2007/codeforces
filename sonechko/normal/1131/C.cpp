#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 2e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i+=2)
        cout<<a[i]<<" ";
    if (n%2==1) n--;
    for (int i=n; i>=1; i-=2)
        cout<<a[i]<<" ";
    cout<<endl;
}