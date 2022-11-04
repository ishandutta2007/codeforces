#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3001;

int T, n, m, l[N], r[N], t[N], tmp[N << 1], len[N], cor[N], f[N << 1];

bool lencmp(int a, int b){
	return r[a] - l[a] < r[b] - l[b];
}

bool corcmp(int a, int b){
	return r[a] < r[b];
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		memset(t, 0, sizeof(int) * (n + 1));
		for(int i = 0; i < n; i++){
			len[i] = cor[i] = i;
			scanf("%d%d", l + i, r + i);
			tmp[i << 1] = l[i], tmp[i << 1 | 1] = r[i];
		}
		sort(tmp, tmp + n * 2);
		m = unique(tmp, tmp + n * 2) - tmp;
		l[n] = 1, r[n] = m, len[n] = n;
		for(int i = 0; i < n; i++){
			l[i] = lower_bound(tmp, tmp + m, l[i]) - tmp + 1;
			r[i] = lower_bound(tmp, tmp + m, r[i]) - tmp + 1;
		}
		sort(len, len + n, lencmp);
		sort(cor, cor + n, corcmp);
		for(int i = 0; i <= n; i++){
			memset(f + l[len[i]] - 1, 0, sizeof(int) * (r[len[i]] - l[len[i]] + 2));
			int p = 0;
			while(p < n && r[cor[p]] < l[len[i]]) p++;
			for(int j = l[len[i]]; j <= r[len[i]]; j++){
				f[j] = f[j - 1];
				while(p < n && r[cor[p]] == j){
					if(cor[p] != len[i] && l[cor[p]] >= l[len[i]])
						f[j] = max(f[l[cor[p]] - 1] + t[cor[p]], f[j]);
					p++;
				}
			}
			t[len[i]] = f[r[len[i]]] + 1;
		}
		printf("%d\n", t[n] - 1);
	}
	return 0;
}