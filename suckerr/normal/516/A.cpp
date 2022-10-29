#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 100000;

int a[N], cover[20];
int n;
char buffer[N];

void divide(int x) {
    for(int i = 2; i <= x; i++) {
        while(x % i == 0) {
            cover[i]++;
            x /= i;
        }
    }
}

void cut(int x) {
    for(int i = 2; i <= x; i++) {
        while(x % i == 0) {
            cover[i]--;
            x /= i;
        }
    }
}

void solve(int x) {
    for(int i = 2; i <= x; i++) {
        cut(i);
    }
}

int main() {
    scanf("%d", &n);
    scanf("%s", buffer + 1);
    for(int i = 1; i <= n; i++) {
        a[i] = buffer[i] - '0';
        if (a[i] == 0 || a[i] == 1) {
            continue;
        }
        for(int j = 2; j <= a[i]; j++) {
            divide(j);
        }
    }
    for(int i = 9; i >= 2; i--) {
        while(cover[i]) {
            solve(i);
            printf("%d", i);
        }
    }
    puts("");
    return 0;
}