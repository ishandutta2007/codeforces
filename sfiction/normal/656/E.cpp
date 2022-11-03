#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[10][10];
int ans;

int f1(int i, int j){
	scanf("%d", &a[i][j]);
	return j == n - 1 ? 0 : f1(i, j + 1);
}

int f2(int i){
	f1(i, 0);
	return i == n - 1 ? 0 : f2(i + 1);
}

int g1(int k, int i, int j){
	a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	return j == n - 1 ? 0 : g1(k, i, j + 1);
}

int g2(int k, int i){
	g1(k, i, 0);
	return i == n - 1 ? 0 : g2(k, i + 1);
}

int g3(int k){
	g2(k, 0);
	return k == n - 1 ? 0 : g3(k + 1);
}

int h1(int i, int j){
	ans = max(ans, a[i][j]);
	return j == n - 1 ? 0 : h1(i, j + 1);
}

int h2(int i){
	h1(i, 0);
	return i == n - 1 ? 0 : h2(i + 1);
}

int main(){
	scanf("%d", &n);
	f2(0);
	g3(0);
	h2(0);
	printf("%d\n", ans);
	return 0;
}