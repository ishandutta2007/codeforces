#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef pair< pair<int, int>, pair<int, int> > seg;
pair<int, int> A[5][5];
bool flag;
int dx, dy;
vector<int> a, b;

bool same(seg i, seg j) {
	if(i.x == j.x && i.y == j.y)	return 1;
	if(i.y == j.x && i.x == j.y)	return 1;
	return 0;
}

int main() {
	//freopen("sample.in", "r", stdin);
	flag = 0;
	a.clear();
	b.clear();
	for(int i = 0; i < 4; i ++) {
		scanf("%d %d %d %d", &A[i][0].x, &A[i][0].y, &A[i][1].x, &A[i][1].y);
		dx = A[i][1].x - A[i][0].x, dy = A[i][1].y - A[i][0].y;
		if((dx && dy) || (!dx && !dy))	flag = 1;
		else if(dx && !dy)	a.push_back(i);
		else b.push_back(i);
	}
	if(flag || a.size() != 2 || b.size() != 2)	printf("NO");
	else{
		if(A[a[0]][0].y == A[a[1]][0].y || A[b[0]][0].x == A[b[1]][0].x)	printf("NO");
		else {
			if(same(make_pair(A[b[0]][0], A[b[0]][1]), make_pair(A[a[0]][0], A[a[1]][0])) && same(make_pair(A[b[1]][0], A[b[1]][1]), make_pair(A[a[0]][1], A[a[1]][1])) || same(make_pair(A[b[1]][0], A[b[1]][1]), make_pair(A[a[0]][0], A[a[1]][0])) && same(make_pair(A[b[0]][0], A[b[0]][1]), make_pair(A[a[0]][1], A[a[1]][1])))	printf("YES");
			else if(same(make_pair(A[b[0]][0], A[b[0]][1]), make_pair(A[a[0]][0], A[a[1]][1])) && same(make_pair(A[b[1]][0], A[b[1]][1]), make_pair(A[a[0]][1], A[a[1]][0])) || same(make_pair(A[b[1]][0], A[b[1]][1]), make_pair(A[a[0]][0], A[a[1]][1])) && same(make_pair(A[b[0]][0], A[b[0]][1]), make_pair(A[a[0]][1], A[a[1]][0])))	printf("YES");
			else	printf("NO");
		}
	}
}