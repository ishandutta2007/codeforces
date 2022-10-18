#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double

const int N = 2e5 + 11;



int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b;
    cin>>a>>b;
    if (a>b) swap(a,b);
    int ans=1000000000;
    for (int d=a; d<=b; d++)
    ans=min(ans,(d-a)*(d-a+1)/2+(b-d)*(b-d+1)/2);
    cout<<ans<<endl;
}