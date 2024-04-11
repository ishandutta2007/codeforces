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
	
	int N, res, i, a;
	scanf("%d", &N);
	res=0;
	for (i=0; i<N; i++) {
		scanf("%d", &a);
		if (a%2) a=0;
		else a=1;
		
		res^=a;
		if (res) puts("1");
		else puts("2");
	}
	
	return 0;
}