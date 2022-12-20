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

int hb(int x){
  int ret = -1;
  while(x){
    x>>=1;
    ret++;
  }
  return ret;
}

int lb(int x){
  return hb(x&-x);
}

int get(int l1, int r1, int l2, int r2){
  int h1, h2;
  int m1, m2;
  if(l1 > r1 || l2 > r2)
    return 0;
  h1 = max(lb(l1), hb(l1^r1));
  h2 = max(lb(l2), hb(l2^r2));
  m1 = l1+(1<<h1)-1 & ~((1<<h1)-1);
  m2 = l2+(1<<h2)-1 & ~((1<<h2)-1);
  /*if(m1 < l1 || m1 > r1)
    cout<<m1<<endl;
  if(m2 < l2 || m2 > r2)
    cout<<m2<<endl;*/
  if(r1-l1+1 == (1<<h1+1)-1){
    if(r2-l2+1 == (1<<h2+1)-1){
      return min(r1-l1+1, r2-l2+1);
    }
    if(h2 <= h1)
      return r2-l2+1;
    return max(get(l1, r1, l2, m2-1), get(l1, r1, m2+1, r2));
  }
  if(r2-l2+1 == (1<<h2+1)-1){
    swap(l1, l2);
    swap(r1, r2);
    swap(h1, h2);
    swap(m1, m2);
    if(h2 <= h1)
      return r2-l2+1;
    return max(get(l1, r1, l2, m2-1), get(l1, r1, m2+1, r2));
  }
  if(h1 != h2){
    if(h2 > h1)
      return max(get(l1, r1, l2, m2-1), get(l1, r1, m2+1, r2));
    else
      return max(get(l2, r2, l1, m1-1), get(l2, r2, m1+1, r1));
  }
  return max(min(m1-l1, m2-l2)+min(r1-m1, r2-m2)+1, max(max(get(l1, m1-1, l2, m2-1), get(l1, m1-1, m2+1, r2)), max(get(m1+1, r1, l2, m2-1), get(m1+1, r1, m2+1, r2))));
}

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int l1, r1, l2, r2;
  cin>>l1>>r1>>l2>>r2;
  cout<<get(l1, r1, l2, r2)<<endl;
  return 0;
}