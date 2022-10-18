#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 11;



void up()
{
    int n,k;
    cin>>n>>k;
    int p1=0,p2=2e8;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        int l=x-k,r=x+k;
        p1=max(p1,l);
        p2=min(p2,r);
    }
    if (p1>p2) cout<<-1<<"\n"; else cout<<p2<<"\n";
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
1 2 3 4 5 6 7 8 9 10
X
2 3 4 5 6 7 8 9 10
  X
2 4 5 6 7 8 9 10
    X
2 4 6 7 8 9 10
      X
**/