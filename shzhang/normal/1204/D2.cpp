#include <cstdio>
#include <algorithm>

using namespace std;

char str[100005];
int s[100005]; int a[100005];
int sufmax[100005];

int main()
{
    scanf("%s", str + 1);
    int n;
    for (int i = 1; str[i]; i++) {
        n = i; s[i] = s[i-1] + (str[i] - '0');
        a[i] = i - 2 * s[i];
    }
    sufmax[n + 1] = -1000000000;
    for (int i = n; i >= 1; i--) {
        sufmax[i] = max(a[i], sufmax[i+1]);
    }
    for (int i = 1; i <= n; i++) {
        //printf("%d ", sufmax[i]);
        if (str[i] == '1' && sufmax[i] < a[i-1]) {
            str[i] = '0';
        }
    }
    printf("%s", str + 1);
    return 0;
}