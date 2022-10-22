#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

void work() {
    int ax , ay , bx , by;
    cin >> ax >> ay >> bx >> by;
    if (ax + ay <= max(bx , by) || bx >= ax && by >= ay) {
        puts("Polycarp");
    } else {
        puts("Vasiliy");
    }
}

int main() {
    work();
    return 0;
}