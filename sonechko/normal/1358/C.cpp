#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 1000 + 11;

void up()
{
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    ll x=(x2-x1+1);
    ll y=(y2-y1+1);
    cout<<1+(x-1)*(y-1)<<"\n";
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
1 1 - 1
1 2 - 1
1 3 - 1
2 1 - 1
2 2 - 2
2 3 - 3
2 4 - 4
3 1 - 1
3 2 - 3
3 3 - 5
3 4 - 7
4 1 - 1
4 2 - 4
4 3 -
**/