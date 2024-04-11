#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 105;
const int Q = 1e9 + 7;

vector<string> V[N];
int n , m , res;

void dfs(string T) {
    if (T.size() == n) {
        ++ res;
        return;
    }
    int c = T.back() - 'a';
    T.pop_back();
    for (auto &S : V[c])
        dfs(T + S);
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < m ; ++ i) {
        string A , B;
        cin >> A >> B;
        reverse(A.begin() , A.end());
        V[B.back() - 'a'].push_back(A);
    }
    dfs("a");
    cout << res << endl;
    return 0;
}