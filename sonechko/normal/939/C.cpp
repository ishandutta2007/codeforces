#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ss second
#define ff first
#define ld long double
#define mp make_pair

const int N = 2e5 + 11;

int a[N],s[N];

int main()
{
          int n;
          cin>>n;
          for (int i=1; i<=n; i++)
          cin>>a[i];
          int l,r;
          int ans=0;
          int tres=0;
          cin>>l>>r;
          r--;
          for (int i=1; i<=n; i++)
          s[i]=s[i-1]+a[i];
          for (int t=1; t<=n; t++)
          {
                    int res=0;
                    int l1=1;
                    if (l>t) l1=l-t+1;
                    int r1=r-t+1;
                    if (r>=t) {res+=s[r1]-s[l1-1];}
                    int ps=n-t+2;
                    l1=ps+l-1;
                    r1=min(n,ps+r-1);
                    if (l<=t-1) { res+=s[r1]-s[l1-1];}
                    if (res>ans) {ans=res; tres=t;}
          }
          cout<<tres<<endl;
}