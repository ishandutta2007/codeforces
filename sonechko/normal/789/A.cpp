#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define ld long double
const int N = 2e5 + 11;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int p=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        p+=(l+m-1)/m;
    }
    cout<<(p+1)/2<<endl;
}