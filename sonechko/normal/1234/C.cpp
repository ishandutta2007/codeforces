#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int t[3][N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        char c;
        cin>>c;
        if (c=='1'||c=='2') t[1][i]=1; else t[1][i]=2;
    }
    for (int i=1; i<=n; i++)
    {
        char c;
        cin>>c;
        if (c=='1'||c=='2') t[2][i]=1; else t[2][i]=2;
    }
    int l=1,r=1,k=1;
    while (1)
    {
        if (r>n)
        {
            if (l==2) {cout<<"YES\n"; return;}
            cout<<"NO\n";
            return;
        }
        if (k==1&&t[l][r]==1) r++; else
        if (k==1&&t[l][r]==2) {l=3-l; k=2;} else
        if (t[l][r]==1) {cout<<"NO\n"; return;} else
        {
            r++;
            k=1;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
        up();
}