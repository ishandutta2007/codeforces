#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 11;



void up()
{
    int n,l,r;
    cin>>n>>l>>r;
    int ans1=n-l,ans2=0;
    for (int j=1; j<=l; j++)
        ans1+=(1<<(j-1));
    for (int j=1; j<=r; j++)
        ans2+=(1<<(j-1));
    for (int j=1; j<=n-r; j++)
        ans2+=(1<<(r-1));
    cout<<ans1<<" "<<ans2<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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