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

const int maxch = (int)1e5;

struct tp{
  int a, b;
};

int first[100100], ans[100100];
int pos[6340001], q[6340001], next[6340001];
tp p[100100];

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  int sz = 0;
  for(int i = 0; i < n; i++){
    int x, y;
    scanf("%d %d", &x, &y);
    for(int j = 1; j * j <= x; j++){
      if(x % j == 0){
	ans[i]++;
	sz++;
	pos[sz] = i;
	q[sz] = y;
	next[sz] = first[j];
	first[j] = sz;
	if(j * j < x){
	  ans[i]++;
	  sz++;
	  pos[sz] = i;
	  q[sz] = y;
	  next[sz] = first[x / j];
	  first[x / j] = sz;
	}
      }
    }
  }
  for(int i = 1; i <= maxch; i++){
    if(first[i] == 0){
      continue;
    }
    int k = 0;
    for(int j = first[i]; j > 0; j = next[j]){
      p[k].a = pos[j];
      p[k].b = q[j];
      k++;
    }
    reverse(p, p + k);
    for(int j = 1; j < k; j++){
      if(p[j].a - p[j - 1].a <= p[j].b){
	ans[p[j].a]--;
      }
    }
  }
  for(int i = 0; i < n; i++){
    printf("%d\n", ans[i]);
  }
  return 0;
}