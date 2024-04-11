#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,p,k;
    cin>>n>>p>>k;
    if (p-k>1) cout<<"<< ";
    for (int d=max(1,p-k); d<p; d++)
        cout<<d<<" ";
    cout<<"("<<p<<") ";
    for (int d=p+1; d<=min(n,p+k); d++)
        cout<<d<<" ";
    if (p+k<n) cout<<">>";
    cout<<endl;
}