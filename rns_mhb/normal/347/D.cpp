#include <bits/stdc++.h>
using namespace std;

#define TOP_N 110

int n, m, s, f[TOP_N], dp[TOP_N][TOP_N][TOP_N];
char a[TOP_N], b[TOP_N], v[TOP_N];

int get (int l, char c){
	while(l > 0 && v[l] != c)	l = f[l - 1];
	if(v[l] == c)	l ++;
	return l;
}

int solve(int i, int j, int k){
    if (i == n || j == m)	return 0;
    if(dp[i][j][k] != -1)	return dp[i][j][k];
    dp[i][j][k] = max(solve(i, j + 1, k), solve(i + 1, j, k));
    if(a[i] == b[j]){
        int kk = get(k, a[i]);
        if(kk < s){
            dp[i][j][k] = max(dp[i][j][k], solve(i + 1, j + 1, kk) + 1);
        }
    }
    return dp[i][j][k];
}

void print(int i, int j, int k){
	if(i == n || j == m) return;
    if(solve(i + 1, j , k) == solve(i, j, k))  return print(i + 1, j, k);
    if(solve(i, j + 1, k) == solve(i, j, k))  return print(i, j + 1, k);
    printf("%c", a[i]);
    return print(i + 1, j + 1, get(k, a[i]));
}

int main(){
//	freopen("sample.in", "r", stdin);
	scanf("%s %s %s", a, b, v);
	n = strlen(a), m = strlen(b), s = strlen(v);
	int l = 0;
	for(int i = 1; i < s; i ++){
		l = get(l, v[i]);
		f[i] = l;
	}
	memset(dp, -1, sizeof(dp));
	if(solve(0, 0, 0))	print(0, 0, 0);
	else	printf("0");
}