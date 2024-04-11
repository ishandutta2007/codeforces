#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

char s[100010];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    char last = 'a' - 1;
    vector<char> ans;
    for (int i = n-1; i>=0; i--) {
        if (s[i] >= last) {
            last = s[i];
            ans.pb(last);
        }
    }
    for (int i = (int)ans.size() - 1; i >= 0; i--)
        printf("%c", ans[i]);
    printf("\n");
    return 0;
}