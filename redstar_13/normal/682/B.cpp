//2016-06-17 11:52:43.894000
#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second
#define beyond(x, y) (x<0 || y<0 || x>=N || y>=M)

typedef long long INT;
typedef pair<int, int> pii;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int a[111111];

int main() {
	
	int n, i, res, j, st;
	scanf("%d", &n);
	for (i=0; i<n; i++) scanf("%d", a+i);
	
	sort(a, a+n);
	st=0;
	for (i=0; i<n; i++) {
		for (j=st; j<n; j++) {
			if (a[j]>=(i+1)) break;
		}
		if (j==n) break;
		st=j+1;
		res=i+2;
	}

	printf("%d\n", res);
	
	return 0; 
}