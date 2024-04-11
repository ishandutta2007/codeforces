#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 1e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int k=0;
    for (int i=1; i<=n; i++)
    {
          int t;
          cin>>t;
          k+=t;
          cout<<k/m<<" ";
          k%=m;
    }
}