#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 11;
#define pb push_back

int a[N],ms;
vector<int> v[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ms=-INT_MAX;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        ms=max(ms,a[i]);
    }
    for (int j=1; j<n; j++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    for (int d=ms; ; d++)
    {
        int p1=0,p2=0;
        for (int i=1; i<=n; i++)
            if (a[i]==d) p1++; else
            if (a[i]==d-1) p2++;
        for (int i=1; i<=n; i++)
        {
            if (a[i]==d) p1--;
            if (a[i]==d-1) p2--;
                for (int j=0; j<v[i].size(); j++)
                {
                    if (a[v[i][j]]==d-1) p2--;
                }
            if (p1==0&&p2==0) {cout<<d<<endl; return 0;}
            for (int j=0; j<v[i].size(); j++)
                {
                    if (a[v[i][j]]==d-1) p2++;
                }
            if (a[i]==d-1) p2++;
            if (a[i]==d) p1++;
        }
    }
}