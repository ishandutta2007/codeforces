#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,x;
        cin>>n>>x;
        cout<<x*2<<"\n";
    }
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