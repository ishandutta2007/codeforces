#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll hx = (ll)(2e5 + 3);
const int mp = (int)(1e6 + 7);

struct ta{
  int x, y;
};

struct tb{
  ll x, y;
  int num;
};

bool operator == (const tb &a, const tb &b){
  return a.x == b.x && a.y == b.y && a.num == b.num;
}

ta a[100100];
tb b[7000000];
int next[7000000];
int first[mp];

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  ll m;
  scanf("%d %I64d %I64d %I64d", &n, &m, &b[0].x, &b[0].y);
  b[0].num = 0;
  for(int i = 0; i < n; i++){
    scanf("%d %d", &a[i].x, &a[i].y);
  }
  for(int i = 0; i < mp; i++){
    first[i] = -1;
  }
  int i = 0;
  int num = 0;
  int pos = -1;
  while(true){
    if(i > 0){
      b[i].x = -b[i - 1].x + 2 * a[num].x;
      b[i].y = -b[i - 1].y + 2 * a[num++].y;
      if(num >= n){
	num = 0;
      }
      b[i].num = num;
    }
    int need = (b[i].x * hx * hx + b[i].y * hx + b[i].num) % mp;
    if(need < 0){
      need += mp;
    }
    for(int j = first[need]; j > -1; j = next[j]){
      if(b[i] == b[j]){
	pos = j;
	break;
      }
    }
    if(pos > -1){
      break;
    }
    next[i] = first[need];
    first[need] = i++;
  }
  if(m < pos){
    printf("%I64d %I64d\n", b[m].x, b[m].y);
    return 0;
  }
  m = (m - pos) % (i - pos);
  printf("%I64d %I64d\n", b[pos + m].x, b[pos + m].y);
  return 0;
}