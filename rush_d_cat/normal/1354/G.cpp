#include <bits/stdc++.h>
using namespace std;
int T, n, k;
int ask(vector<int> A, vector<int> B) {
	printf("? %d %d\n", A.size(), B.size()); fflush(stdout);
	for (int i = 0; i < A.size(); i ++) {
		printf("%d", A[i]);
		if (i == (int)A.size()-1) printf("\n");
		else printf(" ");
	}
	fflush(stdout);

	for (int i = 0; i < B.size(); i ++) {
		printf("%d", B[i]);
		if (i == (int)B.size()-1) printf("\n");
		else printf(" ");
	}
	fflush(stdout);

	char str[10]; scanf("%s", str);
	if (str[0] == 'F') return -1;
	if (str[0] == 'E') return 0;
	if (str[0] == 'S') return 1;
	assert(0);
	return 2;
}
bool ok(int l, int r) {
	vector<int> v1, v2;
	for (int i = 1; i <= r - l + 1; i ++) v1.push_back(i);
	for (int i = l; i <= r; i ++) v2.push_back(i);
	int res = ask(v1, v2);
	if (res == 0) return 0;
	return 1; 
}
int solve(int L, int R) {
	int l = L-1, r = R; 
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (ok(L, mid)) r = mid;
		else l = mid;
	}
	return r;
}

int main() {
	srand(time(0));
	scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &n, &k);
		bool flag = false;
		
		for (int i = 1; i <= 20; i ++) {
			int pos = rand() % n + 1;
			if (pos == 1) continue;
			vector<int> v1, v2; 
			v1.push_back(1);
			v2.push_back(pos);
			int res = ask(v1, v2);
			if (res == 1) {
				printf("! %d\n", 1); fflush(stdout); flag = true;
				break;
			}
		}
		
		if (flag) continue;
		for (int i = 2; i <= n; i *= 2) {
			vector<int> v1, v2;
			for (int j = 1; j <= i / 2; j ++) v1.push_back(j);
			for (int j = i/2 + 1; j <= i; j ++) v2.push_back(j);
			int res = ask(v1, v2);
			if (res == -1) {
				int x = solve(i/2+1, i); 
				printf("! %d\n", x); fflush(stdout);
				flag=true; break;
			}
		} 
		if (flag) continue;
		int now=1;
		while(now*2<=n) now=now*2;
		int x = solve(now+1, n);
		printf("! %d\n", x); fflush(stdout);
	}	
}