#include <bits/stdc++.h>
using namespace std;

int main() {
    int k[3];
    for (int i = 0; i < 3; i ++) scanf("%d", &k[i]);
    sort(k, k + 3);
    if (k[0] > 3) puts("NO");
    else {
		if (k[0] == 1) puts("YES");
        else if (k[0] == 2) {
            if (k[1] == 4 && k[2] == 4 || k[1] == 2) puts("YES");
            else puts("NO");
        }
        else if (k[2] == 3) puts("YES");
        else puts("NO");
    }
}