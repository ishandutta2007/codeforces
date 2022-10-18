#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 11;



void up()
{
    string s;
    cin>>s;
    int n=s.size();
    int ans=(n-1)/2+1;
    if ((n-1)%2==0)
    {
        int t=0;
        for (int j=1; j<n; j++)
            if (s[j]=='1') t=1;
        if (t==0) ans--;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
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