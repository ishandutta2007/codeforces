#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
const int N = 1001;

int t, n, a[N], cnt[N], x[N << 1], k, p;
set<int> st;

int main(){
	scanf("%d", &t);
	while(t--){
		k = p = 0;
		st.clear();
		memset(cnt, 0, sizeof(int) * (n + 1));
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", a + i);
			cnt[a[i]]++;
		}
		for(int i = 0; i <= n; i++)
			if(!cnt[i]) st.insert(i);
		while(p < n && a[p] == p) p++;
		while(p < n){
			int mex = *st.begin();
			st.erase(st.begin());
			cnt[mex]++;
			if(mex == n){
				x[k++] = p + 1;
				if(!--cnt[a[p]]) st.insert(a[p]);
				a[p] = mex;
			}else{
				x[k++] = mex + 1;
				if(!--cnt[a[mex]]) st.insert(a[mex]);
				a[mex] = mex;
			}
			while(p < n && a[p] == p) p++;
		}
		printf("%d\n", k);
		for(int i = 0; i < k; i++)
			printf("%d ", x[i]);
		putchar('\n');
	}
	return 0;
}