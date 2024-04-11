#include<bits/stdc++.h>
using namespace std;

#define INF 2000000000
#define TOP_N 5005

int n, m, up[TOP_N][TOP_N], t[TOP_N], l[TOP_N], r[TOP_N], d[TOP_N], sum[TOP_N], mn[TOP_N];
bool flag, tag;

int main(){
	//freopen("sample.in", "r", stdin);
	scanf("%d %d", &n, &m);
	memset(sum, 0, sizeof(sum));
	for(int i = 1; i <= n; i ++)	mn[i] = INF;
	for(int i = 1; i <= m; i ++){
		scanf("%d %d %d %d", &t[i], &l[i], &r[i], &d[i]);
		if(t[i] == 1){
			for(int j = l[i]; j <= r[i]; j ++)	sum[j] += d[i];
		}
		if(t[i] == 2){
			for(int j = l[i]; j <= r[i]; j ++){
				up[i][j] = d[i] - sum[j];
				if(mn[j] > up[i][j])	mn[j] = up[i][j];
			}
		}
	}
	tag = 0, flag = 0;
	for(int j = 1; j <= m && !flag; j ++){
		if(t[j] == 1)	continue;
		tag = 0;
		for(int i = 1; i <= n && !tag; i ++){
			if(up[j][i] == mn[i])	tag = 1;
		}
		if(tag == 0)	flag = 1;
	}
	if(flag)	printf("NO");
	else{
		printf("YES\n");
		for(int i = 1; i <= n; i ++){
			printf("%d", min(mn[i], 1000000000));
			if(i != n)	printf(" ");
		}
	}	
}