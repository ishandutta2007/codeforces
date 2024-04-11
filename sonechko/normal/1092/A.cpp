#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;

#define ll long long

void up()
{
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cout<<char('a'+(i%k));
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}