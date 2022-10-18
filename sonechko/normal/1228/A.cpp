#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int t[N];

bool good(int x)
{
    for (int i=0; i<=9; i++)
        t[i]=0;
    while (x>0)
    {
        int c=x%10;
        if (t[c]==1) return 0;
        t[c]=1;
        x/=10;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l,r;
    cin>>l>>r;
    for (int p=l; p<=r; p++)
    if (good(p)) {cout<<p; return 0;}
    cout<<-1;
}