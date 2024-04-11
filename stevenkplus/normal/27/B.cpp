#include <cstdio>

using namespace std;

const int MAXN = 110;
int cnts[MAXN];
int wins[MAXN];
int N;

int main() {
scanf("%d", &N);
int num = N * (N - 1) / 2;
for(int i = 1; i < num; ++i) {
int a, b;
scanf("%d %d", &a, &b);
++cnts[a];
++cnts[b];
++wins[a];
}

int a = -1, b;
for(int i = 1; i <= N; ++i) {
if (cnts[i] != N - 1) {
if (a == -1) a = i;
else b = i;
}
}

if (wins[a] >= wins[b]) printf("%d %d\n", a, b);
else printf("%d %d\n", b, a);
return 0;
}