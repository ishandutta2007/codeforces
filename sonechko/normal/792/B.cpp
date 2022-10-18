#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long



const ll N = 2e5 + 11;

int a[N],use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int kol=n, gl=1;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        l++;
        l%=kol;
        if (l==0) l=kol;
        while (l>0)
        {
            if (use[gl]==0) l--;
            if (l==0) break;
            gl++;
            if (gl==n+1) gl=1;
        }
        cout<<gl<<" ";
        kol--;
        use[gl]=1;
        while (use[gl]==1)
        {
            gl++;
            if (gl==n+1) gl=1;
        }
    }
    cout<<endl;
}