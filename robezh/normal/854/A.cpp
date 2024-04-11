#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n % 2 == 1) return !printf("%d %d", n/2, n/2+1);
    if(n % 4 == 0) return !printf("%d %d", n/2-1, n/2+1);
    return !printf("%d %d", n/2-2, n/2+2);
}