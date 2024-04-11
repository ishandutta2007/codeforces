#include<bits/stdc++.h>
using namespace std;
map<int, bool> mmap;
int main(){
	int n, m, ans = false;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		mmap.clear();
		int k, flag = true;
		scanf("%d", &k);
		for(int i = 0; i < k; i++){
			int t; scanf("%d", &t);
			if(mmap[-t]) flag = false;
			mmap[t] = true;
		}
		if(flag) ans = true;
	}
	printf("%s\n", ans ? "YES" : "NO");
	return 0;
}