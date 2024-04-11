#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e6 + 11;

void up()
{
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    int x=(a+c-1)/c;
    int y=(b+d-1)/d;
    if (x+y>k) cout<<-1<<"\n"; else cout<<x<<" "<<y<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}
/**
8
1 1 1 1 210 140 84 60
**/