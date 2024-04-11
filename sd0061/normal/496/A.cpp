#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;


void work() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int res = 1 << 30;
    for (int i = 1 ; i + 1 < n ; ++ i) {
        vector<int> b = a;
        b.erase(b.begin() + i);
        int m = -1 << 30;
        for (int i = 1 ; i < b.size() ; ++ i)
            m = max(m , b[i] - b[i - 1]);
        res = min(res , m);
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}