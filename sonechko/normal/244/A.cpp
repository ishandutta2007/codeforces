#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair
const int N = 1e6 + 11;
int a[N],use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=k; i++)
        {
            cin>>a[i];
            use[a[i]]=1;
        }
    int p=0;
    for (int i=1; i<=k; i++)
    {
        cout<<a[i]<<" ";
        for (int j=2; j<=n; j++)
        {
            p++;
            while (use[p]==1)
                p++;
            cout<<p<<" ";
        }
        cout<<endl;
    }
}