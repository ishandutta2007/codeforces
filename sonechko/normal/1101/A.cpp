#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
    {
        int l,r,d;
        cin>>l>>r>>d;
        int ans=0;
        if (d<l) ans=d; else 
        {
            int p=r/d;
            ans=(p+1)*d;
        }
        cout<<ans<<"\n";
    }
}