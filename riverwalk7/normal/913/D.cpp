#include <bits/stdc++.h>
#define N 300010 
using namespace std;
typedef long long LL;

int n, a[N], t[N], T, tot;
int ss[12345678];
pair<int, int> temp[N]; 

inline int judge(int x){
	tot = 0;
	for (int i = 1; i <= n; i++){
		if (x <= a[i]){
			temp[++tot] = make_pair(t[i], i);
		}
	}
	
	if (tot < x) return T + 233;
	sort(temp + 1, temp + tot + 1);
	int ans = 0;
	for (int i = 1; i <= x; i++){
		ans += temp[i].first;
	}
	return ans;
}

int main(){
    for(int i=1; i<12345678; i++)
    {
        ss[i] = 4*i-3;
    }
	scanf("%d%d", &n, &T);
	for (int i = 1; i <= n; i++){
		scanf("%d%d", &a[i], &t[i]);
	}
	
	int L = 1, R = n, ans = 0;
	while (L <= R){
		int mid = (L + R) >> 1;
		int now = judge(mid);
		if (now <= T){
			ans = mid;
			L = mid + 1;
		} else {
			R = mid - 1;
		}
	}
	judge(ans);
	printf("%d\n%d\n", ans, ans);
	for (int i = 1; i <= ans; i++){
		printf("%d ", temp[i].second);
	}
}