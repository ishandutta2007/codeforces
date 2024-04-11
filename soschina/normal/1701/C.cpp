#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int N = 2e5 + 1;

int t, n, m, a;
int cnt[N];
multiset<int> st;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		memset(cnt + 1, 0, sizeof(int) * n);
		for (int i = 1; i <= m; i++){
			scanf("%d", &a);
			cnt[a]++;
		}
		st.clear();
		for (int i = 1; i <= n; i++){
			st.insert(cnt[i]);
		}
		while(*--st.end() - *st.begin() > 2){
			int x = *st.begin();
			int y = *--st.end();
			st.erase(st.begin());
			st.erase(--st.end());
			st.insert(y - 1);
			st.insert(x + 2);
		}
		printf("%d\n", *--st.end());
	}
	return 0;
}