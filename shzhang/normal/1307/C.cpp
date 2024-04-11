#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define ll long long

char s[100005];
int freq[26];
long long occur[26][26];

int main()
{
    scanf("%s", s + 1);
    for (int i = 1; s[i]; i++) {
        for (int j = 0; j < 26; j++) {
            occur[j][s[i]-'a'] += (long long)freq[j];
        }
        freq[s[i] - 'a']++;
    }
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        ans = max(ans, (long long)freq[i]);
        for (int j = 0; j < 26; j++) {
            ans = max(ans, occur[i][j]);
        }
    }
    printf("%lld", ans);
    return 0;
}