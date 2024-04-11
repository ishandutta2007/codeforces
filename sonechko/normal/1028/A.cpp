#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 3e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int l1=n,l2=m,r1=0,r2=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        char c;
        cin>>c;
        if (c=='B')
        {
            l1=min(l1,i);
            l2=min(l2,j);
            r1=max(r1,i);
            r2=max(r2,j);
        }
    }
    cout<<(l1+r1)/2<<" "<<(l2+r2)/2<<"\n";
}