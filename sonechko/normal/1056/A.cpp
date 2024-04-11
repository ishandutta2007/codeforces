#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int m;
        cin>>m;
        for (int i=1; i<=m; i++)
        {
            int l;
            cin>>l;
            kol[l]++;
        }
    }
    for (int i=1; i<=100; i++)
        if (kol[i]==n) cout<<i<<" ";
    cout<<endl;
}