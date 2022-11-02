#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>
#include <ctime>
#include <cmath>

using namespace std;

long long brutforce(string s, const vector <pair<int, string> >& q) {
}

long long solve(string s, vector <pair<int, string> > transforms) {
}

void run_test() {
    string val = "";
    for (int i = 0; i < 10; ++i) {
        val += rand() % 10 + '0';
    }

    vector <pair<int, string> > trans;
    for (int i = 0; i < 20; ++i) {
        int dig = rand() % 10;
        string buf = "";
        int len = rand() % 20;
        for (int j = 0; j < len; ++j) {
            buf += rand() % 2 + '0';
        }
        trans.push_back(make_pair(dig, buf));
    }
    long long val1 = brutforce(val, trans);
    long long val2 = solve(val, trans);
    if (val1 == val2) {
        cout << "OK" << endl;
    } else {
        cout << val1 << endl;
        cout << val2 << endl;
        cout << val << endl;
        for (int i = 0; i < trans.size(); ++i) {
            cout << trans[i].first << "->" << trans[i].second << endl;
        }
        exit(0);
    }
}

bool check(set<int> his, set<int> other, int k) {
    int total = 0;
    for (set<int>::iterator it = other.begin(); it != other.end(); ++it) {
        int cur = *it;
        if (his.count(cur)) {
            ++total;
        }
    }
    return total * 100 >= his.size() * k;
}

int main() {
    int m, k;
    map<int, set <int> > friends;

    cin >> m >> k;

    set<int> vals;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        friends[a].insert(b);
        friends[b].insert(a);
        vals.insert(a);
        vals.insert(b);
    }

    for (map<int, set<int> >::iterator it = friends.begin(); it != friends.end(); ++it) {
        int cur = it->first;
        set<int> have = it->second;
        vector <int> fr;
        for (set<int>::iterator it2 = vals.begin(); it2 != vals.end(); ++it2) {
            if (*it2 == cur) {
                continue;
            }
            if (have.count(*it2)) {
                continue;
            }
            if (check(have, friends[*it2], k)) {
                fr.push_back(*it2);
            }
        }
        printf("%d: %d", cur, fr.size());
        for (int i = 0; i < fr.size(); ++i) {
            printf(" %d", fr[i]);
        }
        printf("\n");


    }


    return 0;
}