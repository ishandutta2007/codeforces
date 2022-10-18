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
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if (l1==l2) cout<<l1<<" "<<l2+1<<"\n";
        else cout<<l1<<" "<<l2<<"\n";
    }
}