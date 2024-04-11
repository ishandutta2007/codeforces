#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 11;
int use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        use[l]=1;
    }
    int x=1;
    if (use[x]==1) {cout<<1<<endl; return 0;}
    for (int i=1; i<=k; i++)
    {
        int l1,r1;
        cin>>l1>>r1;
        if (l1==x) {x=r1;} else
        if (r1==x) {x=l1;}
        if (use[x]==1) break;
    }
    cout<<x<<endl;
}