#include <bits/stdc++.h>
using namespace std;

int n;
int lmax = 1, rmin = 1000000;

int main() {
    int a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a <= 500000) lmax = max(lmax, a);
        else rmin = min(rmin, a);
    }
    return !printf("%d", max(lmax-1, 1000000-rmin));
}