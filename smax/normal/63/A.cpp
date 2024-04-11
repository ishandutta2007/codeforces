#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> order = {{"rat", 1}, {"woman", 2}, {"child", 2}, {"man", 3}, {"captain", 4}};

struct Person {
    int pos;
    string name, status;

    bool operator < (Person other) const {
        if (order[status] == order[other.status])
            return pos < other.pos;
        return order[status] < order[other.status];
    }
};

Person p[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> p[i].name >> p[i].status;
        p[i].pos = i;
    }

    sort(p, p + n);
    for (int i=0; i<n; i++)
        cout << p[i].name << "\n";

    return 0;
}