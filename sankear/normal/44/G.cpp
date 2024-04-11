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

#define next nnext

typedef long long ll;
typedef long double ld;

const int inf = (int)1e9;

struct tp{
  int x1, x2, y1, y2, z, num;
};

struct tq{
  int x, y, num;
};

struct tr{
  int l, r, ll, rr;
};

bool operator < (const tp &a, const tp &b){
  return a.z < b.z;
}

bool operator < (const tq &a, const tq &b){
  return a.x < b.x;
}

int maxv, cur;
tp p[100100];
tq q[100100];
tr rmq[280100];
int ans[100100], first[100100];
int val[3000100], num[3000100], next[3000100];
int rsq[9000100];

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d %d %d %d %d", &p[i].x1, &p[i].x2, &p[i].y1, &p[i].y2, &p[i].z);
    p[i].num = i;
  }
  int m;
  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    scanf("%d %d", &q[i].x, &q[i].y);
    q[i].num = i;
  }
  sort(p, p + n);
  sort(q, q + m);
  maxv = 1;
  while(maxv < m){
    maxv *= 2;
  }
  for(int i = 0; i < maxv; i++){
    rmq[i + maxv].l = i + 1;
    rmq[i + maxv].r = i + 1;
  }
  for(int i = maxv - 1; i > 0; i--){
    rmq[i].l = rmq[i * 2].l;
    rmq[i].r = rmq[i * 2 + 1].r;
  }
  int sz = 0;
  for(int i = 0; i < m; i++){
    val[++sz] = q[i].y;
    num[sz] = q[i].num;
    next[sz] = first[num[sz]];
    first[num[sz]] = sz;
    rmq[i + maxv].ll = sz;
    rmq[i + maxv].rr = sz;
  }
  for(int i = maxv - 1; i > 0; i--){
    int osz = sz;
    int j = rmq[i * 2].ll;
    int z = rmq[i * 2 + 1].ll;
    while(j > 0 && j <= rmq[i * 2].rr && z > 0 && z <= rmq[i * 2 + 1].rr){
      if(val[j] < val[z]){
	val[++sz] = val[j];
	num[sz] = num[j++];
	next[sz] = first[num[sz]];
	first[num[sz]] = sz;
	continue;
      }
      val[++sz] = val[z];
      num[sz] = num[z++];
      next[sz] = first[num[sz]];
      first[num[sz]] = sz;
    }
    while(j > 0 && j <= rmq[i * 2].rr){
      val[++sz] = val[j];
      num[sz] = num[j++];
      next[sz] = first[num[sz]];
      first[num[sz]] = sz;
    }
    while(z > 0 && z <= rmq[i * 2 + 1].rr){
      val[++sz] = val[z];
      num[sz] = num[z++];
      next[sz] = first[num[sz]];
      first[num[sz]] = sz;
    }
    if(osz < sz){
      rmq[i].ll = osz + 1;
      rmq[i].rr = sz;
    }
  }
  cur = 1;
  while(cur < sz){
    cur *= 2;
  }
  for(int i = 1; i <= sz; i++){
    rsq[i + cur - 1] = num[i];
  }
  for(int i = sz + 1; i <= cur; i++){
    rsq[i + cur - 1] = inf;
  }
  for(int i = cur - 1; i > 0; i--){
    rsq[i] = min(rsq[i * 2], rsq[i * 2 + 1]);
  }
  for(int i = 0; i < m; i++){
    ans[i] = -1;
  }
  for(int i = 0; i < n; i++){
    int gl = -1;
    int l = 0;
    int r = m - 1;
    while(l <= r){
      int mid = (l + r) / 2;
      if(q[mid].x >= p[i].x1){
	gl = mid;
	r = mid - 1;
      }
      else{
	l = mid + 1;
      }
    }
    if(gl == -1){
      continue;
    }
    int gr = -1;
    l = gl;
    r = m - 1;
    while(l <= r){
      int mid = (l + r) / 2;
      if(q[mid].x <= p[i].x2){
	gr = mid;
	l = mid + 1;
      }
      else{
	r = mid - 1;
      }
    }
    if(gr == -1){
      continue;
    }
    int res = inf;
    l = gl + maxv;
    r = gr + maxv;
    while(l <= r){
      if(l % 2 != 0 && rmq[l].ll > 0){
	gl = -1;
	int ll = rmq[l].ll;
	int rr = rmq[l].rr;
	while(ll <= rr){
	  int mid = (ll + rr) / 2;
	  if(val[mid] >= p[i].y1){
	    gl = mid;
	    rr = mid - 1;
	  }
	  else{
	    ll = mid + 1;
	  }
	}
	if(gl != -1){
	  gr = -1;
	  ll = gl;
	  rr = rmq[l].rr;
	  while(ll <= rr){
	    int mid = (ll + rr) / 2;
	    if(val[mid] <= p[i].y2){
	      gr = mid;
	      ll = mid + 1;
	    }
	    else{
	      rr = mid - 1;
	    }
	  }
	  if(gr != -1){
	    ll = gl + cur - 1;
	    rr = gr + cur - 1;
	    while(ll <= rr){
	      res = min(res, rsq[ll]);
	      ll = (ll + 1) / 2;
	      res = min(res, rsq[rr]);
	      rr = (rr - 1) / 2;
	    }
	  }
	}
      }
      l = (l + 1) / 2;
      if(r % 2 == 0 && rmq[r].ll > 0){
	gl = -1;
	int ll = rmq[r].ll;
	int rr = rmq[r].rr;
	while(ll <= rr){
	  int mid = (ll + rr) / 2;
	  if(val[mid] >= p[i].y1){
	    gl = mid;
	    rr = mid - 1;
	  }
	  else{
	    ll = mid + 1;
	  }
	}
	if(gl != -1){
	  gr = -1;
	  ll = gl;
	  rr = rmq[r].rr;
	  while(ll <= rr){
	    int mid = (ll + rr) / 2;
	    if(val[mid] <= p[i].y2){
	      gr = mid;
	      ll = mid + 1;
	    }
	    else{
	      rr = mid - 1;
	    }
	  }
	  if(gr != -1){
	    ll = gl + cur - 1;
	    rr = gr + cur - 1;
	    while(ll <= rr){
	      res = min(res, rsq[ll]);
	      ll = (ll + 1) / 2;
	      res = min(res, rsq[rr]);
	      rr = (rr - 1) / 2;
	    }
	  }
	}
      }
      r = (r - 1) / 2;
    }
    if(res != inf){
      ans[res] = p[i].num;
      for(int j = first[res]; j > 0; j = next[j]){
	int z = j + cur - 1;
	rsq[z] = inf;
	while(z > 1){
	  z /= 2;
	  rsq[z] = min(rsq[z * 2], rsq[z * 2 + 1]);
	}
      }
    }
  }
  for(int i = 0; i < m; i++){
    printf("%d\n", ans[i] + 1);
  }
  return 0;
}