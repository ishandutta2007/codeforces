#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N], f[N], ans;
bool vis[N];
vector<int> b;

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		b.clear();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for(int i = n; i > 0; i--){
			vis[a[i]] = 1;
			while(vis[ans]) ans++;
			f[i] = ans;
		}
		memset(vis, 0, sizeof(bool) * (n + 1));
		int l, r = 0;
		while(r < n){
			l = ++r;
			vis[a[r]] = 1;
			ans = 0;
			while(vis[ans]) ans++;
			while(ans != f[l]){
				r++;
				vis[a[r]] = 1;
				while(vis[ans]) ans++;
			}
			b.push_back(ans);
			for(int i = l; i <= r; i++)
				vis[a[i]] = 0;
		}
		cout << b.size() << endl;
		for(int x : b)
			printf("%d ", x);
		putchar('\n');
	}
	return 0;
}