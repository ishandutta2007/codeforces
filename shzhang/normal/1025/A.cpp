#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

char s[100005];
int freq[26];
int n;

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    if (n == 1) {printf("Yes"); return 0;}
    for (int i = 0; i < n; i++) freq[s[i] - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1) {printf("Yes"); return 0;}
    }
    printf("No");
    return 0;
}