#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1e5 + 11;

int main()
{
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n;
      cin>>n;
      if (n==1) {cout<<1<<" "<<0<<endl; return 0;}
      vector<int> vv;
      int ans2=1;
      for (int i=2; i<=1000000; i++)
      {
          int kol=0;
          while (n%i==0)
          {
              kol++;
              n/=i;
          }
          if (kol>0) {ans2*=i; vv.pb(kol);}
      }
      int ans=0;
      sort(vv.begin(),vv.end());
      int l=vv.back();
      for (int j=0; j<=20; j++)
      if ((1<<j)>=l) {ans=j; break;}
      if (vv[0]!=(1<<ans)) ans++;
      cout<<ans2<<" "<<ans<<endl;
}