#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second

typedef pair<int, int> pii;
typedef long long INT;

int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};

int a[111];

int main() {
	
	int N, i, j, id, val;
	scanf("%d",&N);
	for (i=0; i<N; i++) scanf("%d", a+i);
	
	for (i=0; i<N; i++) {
		id=-1; val=0x3f3f3f3f;
		for (j=i; j<N; j++) {
			if (val>a[j]) {
				val=a[j]; id=j;
			}
		}
		
		for (j=id; j>i; j--) {
			swap(a[j], a[j-1]);
			printf("%d %d\n", j, j+1);
		}
	}
	
	return 0;
}