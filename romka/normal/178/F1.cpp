#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory.h>
#include <cstring>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

struct TrieNode {
    int term;
    int ch[26];
    int cntdown;
    int values[102];

    TrieNode() {
        memset(values, 0xff, sizeof(values));
        memset(ch, 0xff, sizeof(ch));
        term = 0;
    }
};

int C2(int x) {
    return x * (x-1) / 2;
}

class Trie {
public:
    Trie() {
        nodes.pb(TrieNode());
    }

    int addWord(char *s) {
        return addWord(s, 0);
    }

    void calcCnt() {
        calcCnt(0);
    }

    int getValue(int id, int k) {
        if (k == 0) return 0;
        TrieNode& cur = nodes[id];
        if (k > cur.cntdown) k = cur.cntdown;
        if (cur.values[k] != -1) return cur.values[k];
        vector<int> f(k + 1, 0);
        forn(i, 26)
            if (cur.ch[i] != -1) {
                for (int j = k; j >= 1; j--)
                    forn(kp, j + 1) {
                        f[j] = max(f[j], f[kp] + C2(min(j - kp, nodes[cur.ch[i]].cntdown)) + getValue(cur.ch[i], j-kp));
                    }

            }
        return cur.values[k] = f[k];
    }

private:
    vector<TrieNode> nodes;

    int addWord(char* s, int id) {
        for (; *s != 0; s++) {
            int nxt = (*s) - 'a';
            if (nodes[id].ch[nxt] == -1) {
                nodes[id].ch[nxt] = nodes.size();
                nodes.pb(TrieNode());
            }
            id = nodes[id].ch[nxt];
        }
        nodes[id].term++;
        return id;
    }

    int calcCnt(int id) {
        TrieNode& cur = nodes[id];
        cur.cntdown = cur.term;
        forn(i, 26)
          if (cur.ch[i] != -1)
            cur.cntdown += calcCnt(cur.ch[i]);
        return cur.cntdown;
    }
};

Trie trie;
int n, k;
char s[510];

int main()
{
    scanf("%d %d", &n, &k);
    forn(i, n) {
        scanf("%s", s);
        trie.addWord(s);
    }
    trie.calcCnt();
    printf("%d\n", trie.getValue(0, k));
    return 0;
}