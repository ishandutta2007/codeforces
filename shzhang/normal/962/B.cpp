#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, a, b;
char s[200005];

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    scanf("%s", s);
    int placed = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '*') continue;
        if (a + b == 0) break;
        if (!i || s[i-1] == '.' || s[i-1] == '*') {
            if (a > b) {
                a--; s[i] = 'a';
            } else {
                b--; s[i] = 'b';
            }
            placed++;
        }
        if (s[i-1] == 'a' && b) {
            b--; s[i] = 'b'; placed++;
        } else if (s[i-1] == 'b' && a) {
            a--; s[i] = 'a'; placed++;
        }
    }
    //printf("%s\n", s);
    printf("%d", placed);
    return 0;
}