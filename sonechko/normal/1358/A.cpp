#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 4e5 + 11;

void up()
{
    int n,m;
    cin>>n>>m;
    if (n%2==0) cout<<n/2*m<<"\n"; else
    if (m%2==0) cout<<m/2*n<<"\n"; else cout<<(n*m)/2+1<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}