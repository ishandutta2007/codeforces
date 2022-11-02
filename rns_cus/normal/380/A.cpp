#include <bits/stdc++.h>
using namespace std;

#define N 200100

int len[N], c[N], val[N], type[N], arr[N], ans[N], m, n;
long long a[N];

int main() {
///	freopen("in.txt", "r", stdin);
	scanf("%d", &m);
	///cout << m << endl;
	for(int step = 1; step <= m; step ++){
		scanf("%d", type + step);
		if(type[step] == 1){
			scanf("%d ", val + step);
		}
		else{
			scanf("%d %d", len + step, c + step);
		}
	}

	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%I64d", a + i);
	int cur = 1;
	long long lenth = 0;

//	cout << n << endl;

	for(int step = 1; step <= m; step ++){
	//	printf("%d ", step);
		if(cur == n + 1) break;
		if(type[step] == 1){
			if(a[cur] == lenth + 1) ans[cur ++] = val[step];
			if(lenth < 100010) arr[lenth + 1] = val[step];
			lenth ++;
		}
		else{
			long long lenth1 = lenth + 1ll * len[step] * c[step];
			for( long long id = lenth + 1; id <= min(100010ll, lenth1); id ++){
				int pos = (id - lenth) % len[step];
				if(pos == 0) pos = len[step];
				arr[id] = arr[pos];
			}

			while(a[cur] <= lenth1 && cur <= n){

				int pos = (a[cur] - lenth) % len[step];

				if(pos == 0) pos = len[step];

				ans[cur] = arr[pos];
				cur ++;
			}
			lenth = lenth1;
		}
	//	cout << lenth << endl;
	}///puts("");
///	for(int i = 1; i <= 16; i ++) printf("%d ", arr[i]); puts("");
	for(int i = 1; i <= n; i ++) printf("%d ", ans[i]);
}