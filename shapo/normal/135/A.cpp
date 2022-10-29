#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[200000], res[200000];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)scanf("%d", &a[i]);
    sort(a, a + n);
    int cur = 1;
    for (int i = 0; i < n; ++i){
        if (i == n - 1 && a[i] == 1)
        res[i] = 2; else res[i] = cur;
        cur = a[i];
        printf("%d ", res[i]);
    }
    return 0;
}