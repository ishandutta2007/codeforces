#include <bits/stdc++.h>
using namespace std;

#define TOP_N 1000005

int n, m, a[TOP_N], del[TOP_N], sz[TOP_N], L[TOP_N], b[TOP_N], cnt, l[TOP_N], res[TOP_N][30], rl[TOP_N], t, c[TOP_N], mn = 10000000;
int vis[TOP_N], vvis[TOP_N];
bool flag, tag;
vector<int> v;

int main(){
	//freopen("sample.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i ++){
		scanf("%d", &a[i]), vis[a[i]] = 1;
		if(mn > a[i])	mn = a[i];
	}
	L[1] = vis[1];
	for(int i = 2; i < TOP_N; i ++)	L[i] = L[i - 1] + vis[i];
	for(int i = 1; i < TOP_N; i ++){
		if(i < mn)	del[i] = 10000000;
		if(vis[i] == 1)	del[i] = 1;
		else	del[i] = del[i - L[i]] + 1;
	}
	int ccnt = 0;
	int r = 0, j = 0;
	for(int i = 0; i < n; i ++){
		scanf("%d", &b[i]);
		if(b[i] != -1){
			v.push_back(b[i]);
			l[j] = r;
			rl[j] = rl[j - 1] + l[j];
			r = 0;
			j ++;
			c[ccnt ++] = b[i];
		}
		else	r ++, t ++;
	}
	
	for(int j = 0; j < 20; j ++){
		for(int i = 0; i < TOP_N; i ++){
			if(j == 0)	res[i][j] = i - L[i];
			else		res[i][j] = res[res[i][j - 1]][j - 1];
		}
	}
	//for(int i = 1; i < 10; i ++)	cout<<res[i][3];
	cnt = v.size();
	
	for(int i = 0; i < cnt; i ++){
		if(i == 0)	sz[i] = 0;
		else{
			sz[i] = sz[i - 1] + 1;
			int k = l[i];
			while(k){
				int r = 32 - __builtin_clz(k);
				sz[i] = res[sz[i]][r - 1];
				k -= 1 << r - 1;
			}
		}//cout<<sz[i];
		if(del[sz[i] + 1] > t - rl[i])	vvis[i] = 1;
	}
	//for(int i = 0; i < 10; i ++)cout<<vvis[i];
	
	//cout<<endl<<endl;
	flag = 0;
	for(int i = 0; i < cnt; i ++){
		if(vvis[i]){
			flag = 1;
			printf("%d", c[i]);
		}
	}
	if(!flag)	printf("Poor stack!");
}