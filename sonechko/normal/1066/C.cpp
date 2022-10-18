#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int a[N],pos[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    int l=200000;
    int r=l-1;
    for (int i=1; i<=q; i++)
    {
        char ch;
        cin>>ch;
        int t;
        cin>>t;
        if (ch=='L') {l--; a[l]=t; pos[t]=l;} else
        if (ch=='R') {r++; a[r]=t; pos[t]=r;} else
            cout<<min(pos[t]-l,r-pos[t])<<"\n";
    }
}