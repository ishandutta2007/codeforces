#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n , a[N];
char str[N];
int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d\n" , &a[i]);
    }
    for (int i = 0 ; i < n ; ++ i) {
        fgets(str , N , stdin);
        int cnt = 0;
        for (int j = 0 ; str[j] ; ++ j) {
            if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u' || str[j] == 'y') {
                ++ cnt;
            }
        }
        if (cnt != a[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}