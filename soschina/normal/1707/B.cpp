#include <cstdio>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
const int N = 5e5 + 1;

int t, n, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = n; i; i--)
            scanf("%d", &a[i]);
        int len = n;
        while(n > 1){
            for (int i = 1; i < n; i++)
                a[i] -= a[i + 1];
            len--;
            n = min(n, len);
            sort(a + 1, a + 1 + n, greater<int>());
            while(n > 1 && a[n - 1] == 0)
                n--;
        }
        printf("%d\n", a[1]);
    }
    return 0;
}