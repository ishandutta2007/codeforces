#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second

typedef pair<int, int> pii;
typedef long long INT;

int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};

int main() {
	
	int N, no=0, i;
	INT x, a;
	char c;
	scanf("%d%I64d", &N, &x);
	for (i=0; i<N; i++) {
		scanf(" %c  %I64d", &c, &a);
		if (c=='+') x+=a;
		else {
			if (x>=a) x-=a;
			else no++;
		}
	}
	printf("%I64d %d\n", x, no);
	
	
	
	return 0;
}