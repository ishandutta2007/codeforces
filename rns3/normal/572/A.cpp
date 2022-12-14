#include <bits/stdc++.h>
using namespace std;
#define M 200001

int a[M], b[M];

int main(){
	///freopen("1.in", "r", stdin);
	int n, m, nn, mm;
	scanf("%d %d %d %d", &n, &m, &nn, &mm);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i ++) scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    if(a[nn] < b[m - mm + 1]) puts("YES");
    else puts("NO");
}