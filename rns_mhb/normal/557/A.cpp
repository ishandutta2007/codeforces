#include <bits/stdc++.h>
using namespace std;

int n, mini[4], maxi[4];
int a[5];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= 3; i ++)   scanf("%d %d", mini + i, maxi + i);
    a[1] = min(n - mini[2] - mini[3], maxi[1]);
    n -= a[1];
    a[2] = min(n - mini[3], maxi[2]);
    a[3] = n - a[2];
    printf("%d %d %d\n", a[1], a[2], a[3]);
}