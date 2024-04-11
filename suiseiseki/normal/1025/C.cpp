#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5 + 5;

int n, a[N], suml[N], sumr[N];
char s[N];

inline int max(int x, int y) {
    return x > y ? x : y;
}

inline int min(int x, int y) {
    return x > y ? y : x;
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for(int i = 1; i <= n; i++) a[i] = s[i] - '0';
    
    for(int i = 1; i <= n; i++) 
        if(a[i] != a[i - 1]) sumr[i] = sumr[i - 1] + 1;
        else sumr[i] = 1;
    for(int i = n; i >= 1; i--)
        if(a[i] != a[i + 1]) suml[i] = suml[i + 1] + 1;
        else suml[i] = 1;
    
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] != a[i + 1]) 
            ans = max(sumr[i] + suml[i + 1], ans);
        if(a[1] != a[n]) 
            ans = max(min(sumr[n], n - i) + min(suml[1], i), ans);
        ans = max(ans, suml[i]);
        ans = max(ans, sumr[i + 1]);
    }
    
    printf("%d\n", max(ans, 1));
    return 0;
}