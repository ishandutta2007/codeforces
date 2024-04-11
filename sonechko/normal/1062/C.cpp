#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1e5 + 11;
const int MOD = 1e9 + 7;

int k1[N],k0[N];

int step(int l, int k)
{
    if (k==0) return 1;
    if (k%2==1) return (step(l,k-1)*l)%MOD;
    int p=step(l,k/2);
    return (p*1ll*p)%MOD;
}

int get(int n, int m)
{
    /**
    1 1 1 1 0 0 0
    +1
    _ 2 2 2 1 1 1
    +2
    _ _ 4 4 3 3 3
    +4
    _ _ _ 8 7 7 7
    +8
    _ _ _ _ 15 15 15
    + 15   2^n+1-2^0
    _ _ _ _ _ 30 30
    + 30   2^(n+2)-2^1
    _ _ _ _ _ _ 60
    +60    2^(n+3)-2^2
    2^(n+m+1)-2^m
    **/
    int ans=step(2,n+m)-step(2,m);
    ans+=MOD;
    ans%=MOD;
    return ans;
}

int main()
{
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n,q;
      cin>>n>>q;
      for (int i=1; i<=n; i++)
      {
          char ch;
          cin>>ch;
          k1[i]=k1[i-1];
          k0[i]=k0[i-1];
          if (ch=='1') k1[i]++; else k0[i]++;
      }

      for (int i=1; i<=q; i++)
      {
          int l,r;
          cin>>l>>r;
          cout<<get(k1[r]-k1[l-1],k0[r]-k0[l-1])<<"\n";
      }
}