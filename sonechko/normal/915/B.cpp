#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,pos,l,r;
    cin>>n>>pos>>l>>r;
    if (l==1&&r==n) {cout<<0<<endl; return 0;}
    if (l==1)
    {
        int res=abs(r-pos)+1;
        cout<<res<<endl;
        return 0;
    }
    if (r==n)
    {
        int res=abs(l-pos)+1;
        cout<<res<<endl;
        return 0;
    }
    if (pos<=l)
    {
        int res=r-pos+2;
        cout<<res<<endl;
        return 0;
    }
    if (pos>=r)
    {
        int res=pos-l+2;
        cout<<res<<endl;
        return 0;
    }
    int res1=pos-l+1+r-l+1;
    int res2=r-pos+1+r-l+1;
    cout<<min(res1,res2)<<endl;
}