#include<bits/stdc++.h>
using namespace std;

int n;
string v, w;
char ans[10];

int main() {
	scanf("%d", &n);
	int x = 1, y = 1;
	while (x + y <= n) {
		printf("? %d %d %d %d\n", x, y + 1, n, n);
		fflush(stdout);
		scanf("%s", ans);
		if (ans[0] == 'Y') {
			y ++;
			v += 'R';
		}
		else {
			x ++;
			v += 'D';
		}
	}
	x = n, y = n;
	while (x + y > n + 1) {
		printf("? %d %d %d %d\n", 1, 1, x - 1, y);
		fflush(stdout);
		scanf("%s", ans);
		if (ans[0] == 'Y') {
			x --;
			w += 'D';
		}
		else {
			y --;
			w += 'R';
		}
	}
	reverse(w.begin(), w.end());
	cout<<"! "<<v<<w<<endl;
}