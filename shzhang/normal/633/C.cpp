#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cctype>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

struct Trie {
    const char* word;
    Trie* nxt[26];
};

Trie* root;

Trie* mktrie(void)
{
    Trie* trie = new Trie;
    trie->word = NULL;
    for (int i = 0; i < 26; i++) trie->nxt[i] = NULL;
    return trie;
}

void insert_trie(const char* str)
{
    Trie* cur = root;
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (!cur->nxt[tolower(str[i]) - 'a']) {
            cur->nxt[tolower(str[i]) - 'a'] = mktrie();
        }
        cur = cur->nxt[tolower(str[i]) - 'a'];
    }
    cur->word = str;
}

int n, m;
char t[10005];

char s[1005];
bool good[10005];
int nxtpos[10005];
const char* nxtstr[10005];

int main()
{
    scanf("%d", &n);
    scanf("%s", t + 1);
    root = mktrie();
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%s", s);
        char* new_s = new char[strlen(s) + 5];
        strcpy(new_s, s);
        insert_trie(new_s);
    }
    good[n + 1] = true;
    for (int i = n; i >= 1; i--) {
        Trie* cur = root;
        for (int j = i; j <= n; j++) {
            if (!cur->nxt[t[j] - 'a']) break;
            cur = cur->nxt[t[j] - 'a'];
            if (cur->word && good[j + 1]) {
                nxtpos[i] = j + 1;
                nxtstr[i] = cur->word;
                good[i] = true; break;
            }
        }
    }
    /*for (int i = 1; i <= n; i++) {

        printf("%d", (int)good[i]);
    }*/
    int i = 1;
    while (i <= n) {
        printf("%s ", nxtstr[i]);
        i = nxtpos[i];
    }
    return 0;
}