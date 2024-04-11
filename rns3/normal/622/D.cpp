#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
    if(n & 1) {
        printf("%d ", n);
		for(int i = 1; i < n; i += 2) printf("%d ", i);
        for(int i = n; i > 0; i -= 2) printf("%d ", i);
        for(int i = 2; i < n; i += 2) printf("%d ", i);
        for(int i = n - 1; i >= 2; i -= 2) printf("%d ", i);
        return 0;
    }
    for(int i = 1; i < n; i += 2) printf("%d ", i);
    for(int i = n-1 ; i > 0; i -= 2) printf("%d ", i);
    printf("%d ", n);
    for(int i = 2; i < n; i += 2) printf("%d ", i);
    for(int i = n; i >= 2; i -=2) printf("%d ", i);
    return 0;
}