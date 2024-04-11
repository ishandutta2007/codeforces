#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

bool good(int x, int n)
{
        for (int i=2; i<=min(x,(int)sqrt(n)); i++)
        if (n%i==0) return false;
        return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x,y;
    cin>>x>>y;
    for (int i=y; i>=x+1; i--)
    if (good(x,i)) {cout<<i<<endl; return 0;}
    cout<<-1<<endl;
}