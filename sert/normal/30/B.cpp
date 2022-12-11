#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int days[13] = {34, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int d, m, y;

void check(int vd, int vm, int vy) {
    days[2] = (vy % 4 ? 28 : 29);
    if (vm > 12) return;
    if (vd > days[vm]) return;
    vy += 18;
    if (vy > y) return;
    if (vy == y && vm > m) return;
    if (vy == y && vm == m && vd > d) return;
    //cerr << vd << " " << vm << " " << vy << "\n";
    cout << "YES\n";
    exit(0);
}

int main() {
    //freopen("a.in", "r", stdin);
    int vd, vm, vy;
    scanf("%d.%d.%d", &d, &m, &y);
    scanf("%d.%d.%d", &vd, &vm, &vy);
    check(vd, vm, vy);
    check(vd, vy, vm);
    check(vm, vd, vy);
    check(vm, vy, vd);
    check(vy, vm, vd);
    check(vy, vd, vm);
    cout << "NO\n";
}