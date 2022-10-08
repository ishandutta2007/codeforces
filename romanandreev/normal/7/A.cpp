#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <map>
#include <set>
using namespace std;
#define ll int64_t

char a[10][10];
int main() {
  //freopen("a.in","r",stdin);
  //freopen("a.out","w",stdout);
  for (int i=0;i<8;i++){
    for (int j=0;j<8;j++)
      scanf("%c",&a[i][j]);
    scanf("\n");
  }
  int ans=0;
  for (int i=0;i<8;i++){
    int sum=0;
    for (int j=0;j<8;j++){
      if (a[i][j]=='B') sum++;
    }
    if (sum==8) ans++;
  }
  for (int i=0;i<8;i++){
    int sum=0;
    for (int j=0;j<8;j++){
      if (a[j][i]=='B') sum++;
    }
    if (sum==8) ans++;
  }
  if (ans==16) ans=8;
  cout<<ans;
  return 0;
}