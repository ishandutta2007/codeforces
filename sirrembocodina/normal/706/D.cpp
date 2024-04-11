#include <bits/stdc++.h>

using namespace std;

//#define int int64_t

struct trie {
    int cnt;
    int son[2];
    trie() {
        cnt = 0;
        son[0] = son[1] = -1;
    }
} nodes[6001000];


int nodes_sz = 1;
int bit_len = 30;

void add(int x) {
    int cur = 0;
    for (int i = bit_len - 1; ; i--) {
        nodes[cur].cnt++;
        if (i < 0) {
            break;
        }
        int to = bool(x & (1 << i));
        if (nodes[cur].son[to] == -1) {
            nodes[cur].son[to] = nodes_sz++;
        }
        cur = nodes[cur].son[to];
    }
}

void del(int x) {
    int cur = 0;
    for (int i = bit_len - 1; ; i--) {
        nodes[cur].cnt--;
        if (i < 0) {
            break;
        }
        int to = bool(x & (1 << i));
        cur = nodes[cur].son[to];
    }
}

int get_max(int x) {
    int cur = 0;
    int ans = 0;
    for (int i = bit_len - 1; i >= 0; i--) {
        int to = !bool(x & (1 << i));
        if (nodes[cur].son[to] == -1 || nodes[nodes[cur].son[to]].cnt == 0) {
            to = 1 - to;
        }
        cur = nodes[cur].son[to];
        ans *= 2;
        ans += to;
    }
    return ans ^ x;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    add(0);
    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        int x;
        cin >> x;
        if (c == '+') {
            add(x);
        } else if (c == '-') {
            del(x);
        } else {
            cout << get_max(x) << '\n';
        }
    }
}