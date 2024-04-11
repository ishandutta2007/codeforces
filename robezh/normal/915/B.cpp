#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,pos,l,r;
    cin >> n >> pos >> l >> r;
    if(l == 1 && r == n) return !printf("0\n");
    if(l == 1) return !printf("%d", abs(pos-r) + 1);
    if(r == n) return !printf("%d", abs(pos-l) + 1);
    return !printf("%d", r - l + min(abs(pos-r), abs(pos-l)) + 2);

}