#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int x = n / 3, y = n / 3, z = n - x - y;
    for(int i = 1; i <= x; i ++) printf("%d %d\n", 1, 2 * i + 1);
    for(int i = 1; i <= z; i ++) printf("%d %d\n", 0, 2 * i);
    for(int i = 1; i <= y; i ++) printf("%d %d\n", -1, 2 * i + 1);
}