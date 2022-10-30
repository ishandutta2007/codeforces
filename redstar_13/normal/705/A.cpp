#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

typedef pair<int, int> pii;
typedef long long INT;

template <class T> inline void smin(T &a, T b) {if (a>b) a=b;}
template <class T> inline void smax(T &a, T b) {if (a<b) a=b;}

int main() {
	
	int N;
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		if (i) printf(" ");
		if (i%2==0) printf("I hate");
		else printf("I love");
		if (i==N-1) printf(" it");
		else printf(" that");
	}
	puts("");
	
	return 0;
}