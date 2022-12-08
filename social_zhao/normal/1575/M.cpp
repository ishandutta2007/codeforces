#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2005;
int n, m, a[N][N], L[N][N], R[N][N], S[N][N];
char s[N];
struct Vector {
	int x, y; 
	Vector(int a = 0, int b = 0) { x = a, y = b; }
	Vector operator -(Vector b) { return Vector(x - b.x, y - b.y); }
	long double slope() { return (long double)1.0 * y / x; }
};
Vector q[N << 1];
int l, r;

int pw2(int x) { return x * x; }
void push(int x, int y) {
	while(l < r && (q[r] - q[r - 1]).slope() >= (Vector(x, y) - q[r]).slope()) r--;
	q[++r] = Vector(x, y);
}
void clear() { l = 1, r = 0; }

void solve(int nowx) {
	clear();
	for(int i = 1; i <= n; i++) {
		if(L[i][nowx]) 
			push(i, pw2(nowx - L[i][nowx]) + pw2(i));
		if(R[i][nowx] && (!L[i][nowx] || R[i][nowx] - nowx != nowx - L[i][nowx])) 
			push(i, pw2(R[i][nowx] - nowx) + pw2(i));
	}
//	cout << "Convex Hull of nowx = " << nowx << endl;
//	for(int i = l; i <= r; i++) cout << q[i].x << " " << q[i].y << endl;
	for(int i = 1; i <= n; i++) {
		while(l < r && (long double)2.0 * i > (q[l + 1] - q[l]).slope()) ++l;
		S[i][nowx] = q[l].y - 2ll * i * q[l].x + i * i;
	}
}

signed main() {
	n = get() + 1, m = get() + 1;
	for(int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for(int j = 1; j <= m; j++) a[i][j] = s[j] - '0';
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j]) L[i][j] = j;
			else L[i][j] = L[i][j - 1];
		}
		for(int j = m; j >= 1; j--) {
			if(a[i][j]) R[i][j] = j;
			else R[i][j] = R[i][j + 1];
		}
	}
	for(int i = 1; i <= m; i++) 
		solve(i);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans += S[i][j];
	cout << ans;
	return 0;
}