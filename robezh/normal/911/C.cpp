#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3];
    for(int i = 0; i < 3; i++) cin >> a[i];
    sort(a,a+3);
    if(a[0] == 1) return !printf("YES\n");
    if(a[0] == 2 && a[1] == 2) return !printf("YES");
    if(a[0] == 2 && (a[1] == 4 && a[2] == 4)) return !printf("YES");
    if(a[0] == 3 && a[1] == 3 && a[2] == 3) return !printf("YES");
    return !printf("NO");

}