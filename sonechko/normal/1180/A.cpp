#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int res=1,x=0;
    for (int i=2; i<=n; i++)
    {
        x+=4;
        res+=x;
    }
    cout<<res;
}