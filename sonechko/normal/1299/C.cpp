#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double

const int N = 1e6 + 11;

int pos[N];
ll a[N],s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    vector<int> poss;
    poss.pb(n);
    pos[n]=n;
    for (int i=n-1; i>=1; i--)
    {
        pos[i]=poss.back();
        while (poss.size()>1)
        {
            int r1=poss[poss.size()-1];
            int r2=poss[poss.size()-2];
            ld p1=(ld)(s[r1]-s[i-1])/(ld)(r1-i+1);
            ld p2=(ld)(s[r2]-s[i-1])/(ld)(r2-i+1);
            if (p1>p2) poss.pop_back(); else break;
        }
        pos[i]=poss.back();
        ld p1=(ld)(s[pos[i]]-s[i-1])/(ld)(pos[i]-i+1);
        if (p1>a[i]) {pos[i]=i; poss.pb(i);}
    }
    int l=1;
    cout.precision(10);
    cout<<fixed;
    while (l<=n)
    {
        int r=pos[l];
        ld p1=(ld)(s[r]-s[l-1])/(ld)(r-l+1);
        while (l<=r)
        {
            cout<<p1<<"\n";
            l++;
        }
    }
}
/**
4
8 9 6 7

5
8 8 9 6 7
**/