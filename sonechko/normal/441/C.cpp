#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 11;


vector<int> v[N];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int l=1,r=1,type=1;
    for (int p=1; p<=k-1; p++)
    {
        v[p].pb(l);
        v[p].pb(r);
        if (type==1) r++; else r--;
        if (r==0) {l++; r=1; type=1;} else
        if (r==m+1) {l++; r=m; type=2;}
        v[p].pb(l);
        v[p].pb(r);
        if (type==1) r++; else r--;
        if (r==0) {l++; r=1; type=1;} else
        if (r==m+1) {l++; r=m; type=2;}
    }
    while (1==1)
    {
        v[k].pb(l);
        v[k].pb(r);
        if (type==1) r++; else r--;
        if (r==0) {l++; r=1; type=1;} else
        if (r==m+1) {l++; r=m; type=2;}
        if (l>n) break;
    }
    for (int i=1; i<=k; i++)
    {
        cout<<v[i].size()/2<<" ";
        for (int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}