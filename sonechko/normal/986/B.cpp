#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int a[N],pos[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    int kos=0;
    for (int i=1; i<=n; i++)
        if (a[i]!=i)
    {
        int d=pos[i];
        pos[a[i]]=d;
        pos[a[d]]=i;
        swap(a[i],a[d]);
        kos++;
    }
    if (kos%2==n%2) cout<<"Petr\n"; else
    cout<<"Um_nik\n";
}