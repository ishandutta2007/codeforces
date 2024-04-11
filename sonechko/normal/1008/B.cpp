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
    int n;
    cin>>n;
    int x=2e9;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        if (l>r) swap(l,r);
        if (r<=x) x=r; else
        if (l<=x) x=l; else {cout<<"NO"<<endl; return 0;}
    }
    cout<<"YES";
}