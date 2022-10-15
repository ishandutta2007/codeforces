#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>

using namespace std;

char s1[1005];
char s2[1005];

bool isvowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    scanf("%s", s1);
    scanf("%s", s2);
    if (strlen(s1) != strlen(s2)) {
        printf("No"); return 0;
    }
    for (int i = 0; s1[i]; i++) {
        if (isvowel(s1[i]) && isvowel(s2[i])) continue;
        if ((!isvowel(s1[i])) && (!isvowel(s2[i]))) continue;
        printf("No"); return 0;
    }
    printf("Yes"); return 0;
}