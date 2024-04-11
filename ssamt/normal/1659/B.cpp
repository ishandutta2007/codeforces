#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &k);
		string s;
		cin >> s;
		vector<int> a;
		vector<int> count(n, 0);
		for(i=0; i<n; i++) {
			a.push_back((k%2)?'1'-s[i]:s[i]-'0');
		}
		for(i=0; k>0 && i<n; i++) {
			if(a[i] == 0) {
				count[i]++;
				a[i] = 1;
				k--;
			}
		}
		count.back() += k;
		if(k%2 == 1) {
			a.back() = 0;
		}
		for(i=0; i<n; i++) {
			printf("%d", a[i]);
		}
		printf("\n");
		for(i=0; i<n; i++) {
			printf("%d ", count[i]);
		}
		printf("\n");
	}
}