#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
int t,a,b,c,ans;
int f[101][101][101];
int main()
{
    cin >>t;
    while(t--)
    {
      memset(f,0,sizeof(f));
      ans=-100000000;
      cin >>a>>b>>c;
      f[a][b][c]=1;
      for(int i=a;i>=0;i--)
        for(int j=b;j>=0;j--)
          for(int k=c;k>=0;k--)
          {
            if(i-1>=0 && j-2>=0)f[i-1][j-2][k]|=f[i][j][k];
            if(j-1>=0 && k-2>=0)f[i][j-1][k-2]|=f[i][j][k];
            if(f[i][j][k])ans=max(ans,a-i+b-j+c-k);
          }
      cout <<ans<<endl;
    }
    return 0;
}