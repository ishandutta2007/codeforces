#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;

void up()
{
    int n,a,b;
    cin>>n>>a>>b;
    for (int i=0; i<n; i++)
        if (i%a<b) cout<<char(i%a+'a');
    else cout<<char(b-1+'a');
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}