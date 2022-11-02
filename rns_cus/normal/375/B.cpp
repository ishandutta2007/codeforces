#include<bits/stdc++.h>
using namespace std;

#define N 5050

char s[N][N];
int n, m, hk[N], q[N], mx;

int main(){
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++){
		scanf("%s", s[i] + 1);
	}
	for(int h = 1; h <= m; h ++){
		for(int i = 1; i <= n; i ++){
			if(s[i][h] == '0') q[i] = hk[i] = 0;
			else{
				hk[i] ++;
				q[i] = hk[i];
			}
		}
		sort(q + 1, q + n + 1);
	//	for(int i = 1; i <= n; i ++) printf("%d ", q[i]); puts("");
		for(int i = 1; i <= n; i ++){
			int tmp = (n + 1 - i) * q[i];
			if(mx < tmp) mx = tmp;
		}
	}
	printf("%d\n", mx);
}