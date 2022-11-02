#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    if (n & 1) return puts("contest"), 0;
    return puts("home"), 0;
}