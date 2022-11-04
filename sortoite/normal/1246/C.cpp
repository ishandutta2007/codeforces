#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define pb push_back
typedef double DO;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

const int NN = 2020;
const int mod = 1e9+7;

int B[2][NN][NN];

inline void add(int& a, int b) {
  a+=b; if(a>=mod) a-=mod;
}

void add(int id, int i, int u, int d) {
  for(; u>0; u-=u&-u) add(B[id][i][u], d);
}

int calc(int id, int i, int u) {
  int ans=0;
  for(; u<NN; u+=u&-u) add(ans, B[id][i][u]);
  return ans;
}

char s[NN][NN];
int a[2][NN][NN];
int dp[NN][NN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  int n, m;
  scanf("%d %d", &n, &m);
  if(n == 1 && m == 1) {
    puts("1");
    return 0;
  }
  for(int i=1; i<=n; i++) {
    scanf("%s", s[i]+1);
  }
  for(int i=n; i>=1; i--) {
    for(int j=m; j>=1; j--) {
      if(s[i][j] == 'R') a[0][i][j]=a[1][i][j]=1;
      if(i<n) a[0][i][j]+=a[0][i+1][j];
      if(j<m) a[1][i][j]+=a[1][i][j+1];
    }
  }
  add(0, 1, 1, 1);
  add(1, 1, 1, 1);
  for(int i=1; i<=n; i++) {
    for(int j=1+(i==1); j<=m; j++) {
      int dp0=0, dp1=0;
      if(i>1 && a[0][i][j]<=n-i) {
        int st=0, ed=i-1, md;
        while(st+1<ed) {
          md=st+ed>>1;
          if(a[0][md+1][j]<=n-i) ed=md;
          else st=md;
        }
        dp0=calc(1, j, ed);
      }
      if(j>1 && a[1][i][j]<=m-j) {
        int st=0, ed=j-1, md;
        while(st+1<ed) {
          md=st+ed>>1;
          if(a[1][i][md+1]<=m-j) ed=md;
          else st=md;
        }
        dp1=calc(0, i, ed);
      }
      add(0, i, j, dp0);
      add(1, j, i, dp1);
      dp[i][j]=(dp0+dp1)%mod;
    }
  }
  cout<<dp[n][m]<<endl;
  return 0;
}