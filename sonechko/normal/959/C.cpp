#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int N = 1e5 + 11;

int main()
{
    int n;
    cin>>n;
    if (n<=5) cout<<-1<<"\n"; else
    {
        for (int i=4; i<=n; i++)
            cout<<1<<" "<<i<<"\n";
        cout<<4<<" "<<2<<"\n";
        cout<<4<<" "<<3<<"\n";
    }
    for (int i=2; i<=n; i++)
        cout<<1<<" "<<i<<"\n";
}