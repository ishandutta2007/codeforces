//2016-06-14 11:47:03.805000
#include <bits/stdc++.h>

using namespace std;

#define beyond(x, y) (x<0 || y<0 || x>=N || y>=M)
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};


int main() {
	
	int N, yes=0, i, u, v;
	char s[1111];
	scanf("%d", &N);
	for (i=0; i<N; i++) {
		scanf("%s%d%d",s, &u, &v);
		if (u>=2400 && v>u) yes=1;
	}
	if (yes) puts("YES");
	else puts("NO");
	return 0; 
}