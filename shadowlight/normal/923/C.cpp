#include <iostream>
#include <vector>

using namespace std;

template<typename T>
istream &operator>>(istream &in, vector<T> &a) {
    for (auto &item : a) {
        in >> item;
    }
    return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (auto &item : a) {
        out << item << " ";
    }
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, vector<vector<T>> &a) {
    for (auto &item : a) {
        out << item << "\n";
    }
    return out;
}

const int MAXLOG = 30;

struct Bor {
    struct Node {
        int cnt;
        int nt[2];

        Node() : cnt(0) {
            fill_n(nt, 2, -1);
        }
    };

    vector<Node> bor;

    void insert(int mask) {
        int v = 0;
        for (int i = MAXLOG; i >= 0; --i) {
            int c = (mask >> i) & 1;
            if (bor[v].nt[c] == -1) {
                bor[v].nt[c] = bor.size();
                bor.push_back(Node());
            }
            v = bor[v].nt[c];
            bor[v].cnt++;
        }
    }

    int find(int mask) {
        int v = 0;
        int res = 0;
        for (int i = MAXLOG; i >= 0; --i) {
            int c = (mask >> i) & 1;
            if (bor[v].nt[c] == -1 || !bor[bor[v].nt[c]].cnt) {
                v = bor[v].nt[1 - c];
                res |= 1 << i;
            } else {
                v = bor[v].nt[c];
            }
            bor[v].cnt--;
        }
        return res;
    }

    Bor() {
        bor.push_back(Node());
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    cin >> a >> p;
    Bor b;
    for (int i = 0; i < n; ++i) {
        b.insert(p[i]);
    }
    for (int i = 0; i < n; ++i) {
        cout << b.find(a[i]) << " ";
    }
    return 0;
}