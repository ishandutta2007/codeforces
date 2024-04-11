#include <cstdio>
bool solve() {
int a, b;
scanf("%d %d", &a, &b);
if (b > 1) return true;
int ar[a];
int j;
for(int i = 0; i < a; ++i) {
scanf("%d", ar + i);
if (ar[i] == 0) j = i;
}
scanf("%d", ar + j);
for(int i = 0; i + 1 < a; ++i) {
if (ar[i] >= ar[i + 1]) {
return true;
}
}
return false;

}
int main() {
if (solve()) {
printf("Yes\n");
} else {
printf("No\n");
}
return 0;
}