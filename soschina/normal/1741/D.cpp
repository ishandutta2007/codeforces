#include <cstdio>
#include <iostream>
using namespace std;
const int N = 262145;

int t, n, a[N];

int solve(int l, int r){
    if(l == r)
        return 0;
    int mid = (l + r) >> 1;
    int ansl = solve(l, mid);
    int ansr = solve(mid + 1, r);
    if(ansl == -1 || ansr == -1)
        return -1;
    if(a[mid] + 1 == a[mid + 1])
        return ansl + ansr;
    if(a[r] + 1 != a[l])
        return -1;
    for (int i = l; i <= mid; i++)
        swap(a[i], a[i + r - mid]);
    return ansl + ansr + 1;
}

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        printf("%d\n", solve(1, n));
    }
	return 0;
}