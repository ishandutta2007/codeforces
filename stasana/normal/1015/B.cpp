#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

template<class T>
T input() {
    T value;
    cin >> value;
    return value;
}

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

bool checkSolution(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    start();

    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    if (!checkSolution(s1, s2)) {
        cout << -1;
        return 0;
    }

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        int ptr = i;
        while (s1[ptr] != s2[i]) {
            ++ptr;
        }
        while (ptr != i) {
            res.push_back(ptr);
            swap(s1[ptr - 1], s1[ptr]);
            --ptr;
        }
    }

    cout << res.size() << endl;
    for (auto i : res) {
        cout << i << " ";
    }
    return 0;
}