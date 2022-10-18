#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int xx=-1000000000;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (l<0) xx=max(xx,l); else
        if (l!=0)
        {
            int d=(int)sqrt(l);
            if (d*d!=l) xx=max(xx,l);
        }
    }
    cout<<xx<<endl;
}