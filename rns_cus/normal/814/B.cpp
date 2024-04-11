#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 100010

int a[N], b[N], vis[N], id[10], cur[10], gas, cnt, n;

int main(){

	///freopen("in.txt", "r", stdin);

	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 1; i <= n; i ++) scanf("%d", b + i);

	for(int i = 1; i <= n; i ++){
		if(a[i] != b[i]) id[cnt ++] = i;
		else vis[a[i]] = true;
	}
	if(cnt == 1){
      for(int i = 1; i <= n; i ++){
			if(!vis[i]) cur[gas ++] = i;
      }
      if(cur[0] == a[id[0]] || cur[0] == b[id[0]]) assert(0);
      for(int i = 1; i <= n; i ++){
			if(i != id[0]) printf("%d ", a[i]);
			else printf("%d ", cur[0]);
      }
      return 0;
	}

	for(int i = 1; i <= n; i ++){
		if(!vis[i]) cur[gas ++] = i;
	}

	assert(gas == 2);

	if((a[id[0]] == cur[0]) && (a[id[1]] != cur[1]) && (b[id[0]] != cur[0]) && (b[id[1]] == cur[1])){
		for(int i = 1; i <= n; i ++){
			if(i == id[0]) printf("%d ", cur[0]);
			else if(i == id[1]) printf("%d ", cur[1]);
			else printf("%d ", a[i]);
		}
	}
	else if((a[id[0]] == cur[1]) && (a[id[1]] != cur[0]) && (b[id[0]] != cur[1]) && (b[id[1]] == cur[0])){
		for(int i = 1; i <= n; i ++){
			if(i == id[0]) printf("%d ", cur[1]);
			else if(i == id[1]) printf("%d ", cur[0]);
			else printf("%d ", a[i]);
		}
	}
	else if((a[id[0]] != cur[0]) && (a[id[1]] == cur[1]) && (b[id[0]] == cur[0]) && (b[id[1]] != cur[1])){
		for(int i = 1; i <= n; i ++){
			if(i == id[0]) printf("%d ", cur[0]);
			else if(i == id[1]) printf("%d ", cur[1]);
			else printf("%d ", a[i]);
		}
	}
	else if((a[id[0]] != cur[1]) && (a[id[1]] == cur[0]) && (b[id[0]] == cur[1]) && (b[id[1]] != cur[0])){
		for(int i = 1; i <= n; i ++){
			if(i == id[0]) printf("%d ", cur[1]);
			else if(i == id[1]) printf("%d ", cur[0]);
			else printf("%d ", a[i]);
		}
	}
	else {
		assert(0);
	}
}