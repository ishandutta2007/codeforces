#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long INT;
map<pii, int> mp;
#define x first
#define y second

char pat[11][11]={"123", "456", "789", "*0*"};
pii pos[11], p[11], vec[11];

int main() {
	
	int n, i, d, j, num;
	char c;
	pii now;
	mp.clear();
	
	for (i=0; i<4; i++) for (j=0; j<3; j++) {
		if (isdigit(pat[i][j])) {
			num=pat[i][j]-'0';
			mp[pii(i, j)]=num;
			p[num]=pii(i, j);
		}
	}
	
	scanf("%d", &n);
	
	for (i=0; i<n; i++) {
		scanf(" %c ", &c);
		d=c-'0';
		pos[i]=p[d];
	}
	
	for (i=0; i<n-1; i++) {
		vec[i]=pii(pos[i+1].x-pos[i].x, pos[i+1].y-pos[i].y);
	}
	
	for (i=0; i<10; i++) {
		if (p[i]==pos[0]) continue;
		now=p[i];
		for (j=0; j<n-1; j++) {
			now=pii(now.x+vec[j].x, now.y+vec[j].y);
			if (mp.count(now)==0) break;
		}
		
		if (j==n-1) break;
	}
	
	if (i<10) puts("NO");
	else puts("YES");
	
	return 0;
}