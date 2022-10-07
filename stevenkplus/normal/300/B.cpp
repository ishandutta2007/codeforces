#include <cstdio>
#include <vector>

using namespace std;

#define sz(x) int((x).size())

const int MAXN = 50;

int par[MAXN];
vector<int> guise[MAXN];


int find(int x) {
if (par[x] == x) return x;
return par[x] = find(par[x]);
}

void merge(int a, int b) {
a = find(a);
b = find(b);
par[a] = b;
}

int N, M;

int main() {
scanf("%d %d", &N, &M);
for(int i = 1; i <= N; ++i) {
par[i] = i;
}
for(int i = 0; i < M; ++i) {
int a, b;
scanf("%d %d", &a, &b);
merge(a, b);
}

vector<int> singles;
vector<int> pairs;
vector<int> trips;

for(int i = 1; i <= N; ++i) {
guise[find(i)].push_back(i);
}
for(int i = 1; i <= N; ++i) {
int s = sz(guise[i]);
if (s == 0) continue;
if (s == 1) singles.push_back(i);
else if (s == 2) pairs.push_back(i);
else if (s == 3) trips.push_back(i);
else {
printf("-1\n");
return 0;
}
}

int a = sz(singles);
int b = sz(pairs);
int c = sz(trips);
int left = a - b;
if (left < 0 || left % 3) {
printf("-1\n");
return 0;
}

for(int i = 0; i < b; ++i) {
printf("%d %d %d\n", singles[i], guise[pairs[i]][0], guise[pairs[i]][1]);
}

for(int i = b; i < a; ++i) {
printf("%d", singles[i]);
if ((a-i)% 3) printf(" ");
else printf("\n");
}

for(int i = 0; i < c; ++i) {
printf("%d %d %d\n", guise[trips[i]][0], guise[trips[i]][1], guise[trips[i]][2]);
}

return 0;
}