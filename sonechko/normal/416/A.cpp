#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int xx=-2e9,yy=2e9;
    for (int i=1; i<=n; i++)
    {
        string s,t;
        int k;
        cin>>s>>k>>t;
        if (t=="N")
        {
            if (s==">") s="<="; else
            if (s=="<") s=">="; else
            if (s=="<=") s=">"; else s="<";
        }
        if (s==">") xx=max(xx,k+1);
        if (s=="<") yy=min(yy,k-1);
        if (s==">=") xx=max(xx,k);
        if (s=="<=") yy=min(yy,k);
    }
    if (xx<=yy) cout<<xx<<endl; else cout<<"Impossible"<<endl;
}