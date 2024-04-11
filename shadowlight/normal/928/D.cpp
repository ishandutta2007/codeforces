#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int Q = 31;

vector <string> words;

struct TNode {
    vector <TNode*> edges;
    int cnt;
    bool term;
};

TNode *new_node() {
    vector <TNode*> edges(Q, nullptr);
    return new TNode({edges, 0, false});
}

int res = 0;

void add(TNode *root, string &s) {
    TNode *start = root;
    int l = 0, r = 0;
    int n = s.size();
    bool fl = false;
    for (int i = 0; i < n; i++) {
        int k = s[i] - 'a';
        if (!root->edges[k]) {
            root->edges[k] = new_node();
        }
        root = root->edges[k];
        if (!l && root->cnt == 1) {
            l = i + 1;
        }
        if (l && root->term) {
            r = i + 1;
        }
        root->cnt++;
    }
    //cout << s << " ";
    if (l && r && n > (n - r) + l) {
        //cout << (n - r) + l + 1 << "\n";
        res += (n - r) + l + 1;
    } else {
        //cout << n << "\n";
        res += n;
    }
    if (!root->term) {
        root->term = 1;
        return;
    }
    root = start;
    for (int i = 0; i < n; i++) {
        int k = s[i] - 'a';
        root = root->edges[k];
        root->cnt--;
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    string s;
    int space = 0;
    TNode *root = new_node();
    while (getline(cin, s)) {
        string word = "";
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                word += c;
                continue;
            }
            space++;
            if (word.size()) {
                words.push_back(word);
            }
            word = "";
        }
        space++;
        if (word.size()) {
            words.push_back(word);
        }
    }
    for (string word : words) {
        //cout << word << " " << word.size() << "\n";
        add(root, word);
    }
    cout << space + res << "\n";
}