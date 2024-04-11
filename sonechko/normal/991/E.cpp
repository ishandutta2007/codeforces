#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = 1000 + 11;

int kk[N];
int dd[N];
ll ans=0;
ll fac[N];

void dfs(int l)
{
      if (l==10)
      {
            //for (int p=0; p<=9; p++)
            //cout<<dd[p];
            //cout<<endl;
            for (int p=1; p<=9; p++)
            if (dd[p]>0)
            {
                  dd[p]--;
                  int ks=0;
                  for (int j=0; j<=9; j++)
                  ks+=dd[j];
                  ll res=fac[ks];
                  for (int j=0; j<=9; j++)
                  res/=fac[dd[j]];
                  ans+=res;
                  //cout<<p<<" - "<<res<<endl;
                  dd[p]++;
            }
            return;
      }
      if (kk[l]==0) dfs(l+1);
      for (int j=1; j<=kk[l]; j++)
      {
            dd[l]=j;
            dfs(l+1);
      }
}

int main()
{
     string s;
     cin>>s;
     for (int j=0; j<s.size(); j++)
     kk[s[j]-'0']++;
     fac[0]=1;
     for (int j=1; j<=20; j++)
     fac[j]=fac[j-1]*1ll*j;
     dfs(0);
     cout<<ans<<endl;
}