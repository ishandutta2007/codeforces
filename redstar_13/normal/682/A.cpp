//2016-06-17 11:41:19.588000
#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second
#define beyond(x, y) (x<0 || y<0 || x>=N || y>=M)

typedef long long INT;
typedef pair<int, int> pii;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

INT a[11], b[11];
int main() {
	
	int n, m, i;
	INT res;
	scanf("%d%d", &n, &m);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	
	for (i=1; i<=n; i++) a[i%5]++;
	for (i=1; i<=m; i++) b[i%5]++;
	res=0;
	for (i=0; i<5; i++) res+=a[i]*b[(5-i)%5];
	printf("%I64d\n", res);
	
	return 0; 
}