#include <bits/stdc++.h>
using namespace std;
#define N 100005

int a[N], sum[N], id[N], tot, pnt, qnt, sz;
int b[N], c[N], amn, sm[N], d[N];

priority_queue <int> pq;
stack <int> stk;

bool cmp(int i, int j){
	return a[i] < a[j];
}

int main(){
//	freopen("1.in", "r", stdin);
	int i, j, n, ans = 300 * N, x, v, sumds;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", a + i);
	for(i = 0; i < n; i++){
		scanf("%d", d + i);
		sum[a[i]] += d[i];
		id[i] = i;
	}
	sort(id, id + n, cmp);
	i = 0;
	while(i < n){
		j = 0;
		while(a[id[i]] == a[id[i + j]] && i + j < n) j++;
		b[pnt] = a[id[i]];
		c[pnt] = j;
		i += j;
		pnt++;
	}
	tot = 0;
	for(i = 0; i < pnt; i++){
		tot += sum[b[i]];
		sm[i] = tot;
	}
	i = 0; qnt = 0;
	while(i < n){
		x = tot - sm[qnt];
		if(sz >= c[qnt]){
			v = c[qnt] - 1;
			sumds = 0;
			while(v--){
				j = pq.top();
				stk.push(j);
				sumds += j;
				pq.pop();
			}
			x += sm[qnt - 1] - sumds;
			while(!stk.empty()){
				pq.push(stk.top());
				stk.pop();
			}
		}
		if(x < ans) ans = x;
		while(b[qnt] == a[id[i]]){
			pq.push(d[id[i]]);
			i++;
			sz++;
		}
		qnt++;
	}
	printf("%d", ans);
}