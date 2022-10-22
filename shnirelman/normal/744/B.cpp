//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 400;

mt19937 rnd(0);

int n;

vector<int> get(vector<int> a) {
    cout << a.size() << endl;
    for(auto x : a)
        cout << x + 1 << ' ';
    cout << endl;

    vector<int> res(n);
    for(int i = 0; i < n; i++)
        cin >> res[i];

    return res;
}



int main() {

    cin >> n;

    vector<int> ans(n, INF);
    for(int i = 0; (1 << i) < n; i++) {
        for(int b = 0; b < 2; b++) {
            vector<int> a;
            for(int j = 0; j < n; j++)
                if(((j >> i) & 1) == b)
                    a.push_back(j);

            auto res = get(a);
            for(int j = 0; j < n; j++)
                if(((j >> i) & 1) != b) {
                    ans[j] = min(ans[j], res[j]);
                }

        }
    }

    cout << -1 << endl;
    for(auto x : ans)
        cout << x << ' ';
    cout << endl;
}