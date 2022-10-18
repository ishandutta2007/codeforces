#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

const int N = 1e5 + 11;

int kol[N],kos[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        kol[l]+=10;
        kos[l]+=r;
    }
    for (int l=1; l<=2; l++)
    if (kol[l]>kos[l]*2) cout<<"DEAD\n"; else cout<<"LIVE\n";
}