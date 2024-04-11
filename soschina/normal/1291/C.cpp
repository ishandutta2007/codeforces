#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
const int N = 3501;

int t, n, m, k, a[N], ans;

int main(){
	scanf("%d", &t);
	while(t--){
		multiset<int> s;
		ans = 0;
		scanf("%d%d%d", &n, &m, &k);
		k = k < m ? m - k : 1;
		for(int i = 1; i <= n; i++)
			scanf("%d", a + i);
		for(int i = 1; i <= m; i++)
			a[i] = max(a[i], a[i + n - m]);
		for(int i = 1; i < k; i++)
			s.insert(a[i]);
		for(int i = k; i <= m; i++){
			s.insert(a[i]);
			ans = max(ans, *s.begin());
			s.erase(s.find(a[i - k + 1]));
		}
		printf("%d\n", ans);
	}
	return 0;
}