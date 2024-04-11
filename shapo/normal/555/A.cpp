#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair< int, int > pii;
typedef vector< int > vi;

int
main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector< vi > mat;
    for (int i = 0; i < k; ++i) {
        int len;
        cin >> len;
        mat.emplace_back(len);
        auto &tmp = mat.back();
        for (int j = 0; j < len; ++j) {
            cin >> tmp[j];
        }
    }
    int pos = 0;
    while (mat[pos][0] != 1) ++pos;
    int id = 0;
    int cnt = mat[pos].size();
    while (id < cnt && mat[pos][id] == id + 1) ++id;
    int res = 0;
    // cerr << id << endl;
    if (id < cnt) {
        res = (n - id) + (n - id) - (k - 1);
    } else {
        res = (n - id) + (n - id) - (k - 1);
    }
    cout << res << '\n';
    return 0;
}