#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

bool p[100000];
int p1[5][10000];
char s[10];
int a[10][10];
int n;
ll ans;

void com(){
  ll t = 1;
  for(int i = 1; i < n; i++){
    int x = 0;
    for(int j = 0; j < n; j++)if(j != i)
      x = x*10+a[i][j];
    t *= p1[n-i-1][x];
  }
  ans += t;
}

void dfs(int i, int j){
  if(j == n){
    i++;
    j = i+1;
  }
  if(i >= n-1){
    com();
    return;
  }
  for(int x = 0; x < 10; x++){
    a[i][j] = a[j][i] = x;
    dfs(i, j+1);
  }
}

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int i, j;
  memset(p, 1, sizeof p);
  p[0] = p[1] = 0;
  for(i = 2; i < 100000; i++){
    if(p[i]){
      if(i*i >= 100000)
        break;
      for(j = i*i; j < 100000; j += i)
        p[j] = false;
    }
  }
  for(i = 0; i < 100000; i++){
    p1[0][i/10] += p[i];
    p1[1][i%10+i/100*10] += p[i];
    p1[2][i%100+i/1000*100] += p[i];
    p1[3][i%1000+i/10000*1000] += p[i];
    p1[4][i%10000+i/100000*10000] += p[i];
  }
  int t, i0;
  scanf("%d", &t);
  for(i0 = 0; i0 < t; i0++){
    scanf("%s", &s);
    n = strlen(s);
    for(i = 0; i < n; i++)
      a[0][i] = a[i][0] = s[i]-'0';
    ans = 0;
    dfs(1, 2);
    cout<<ans<<endl;
  }
  return 0;
}