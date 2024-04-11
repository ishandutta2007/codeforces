#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const int Q = 1e9 + 7;
int n , m , cnt[N];
int r;
vector<int> p[N];

int main() {
    scanf("%d%d" , &m , &n);
    for (int i = 0 ; i < m ; ++ i) {
        int k , x;
        scanf("%d" , &k);
        map<int , int> H;
        while (k --) {
            scanf("%d" , &x);
            ++ H[x];
        }
        map<int , vector<int> > A;
        for (auto &it : H) {
            A[it.second].push_back(it.first);
        }
        for (auto &it : A) {
            for (auto &x : it.second) {
                p[x].push_back(r);
            }
            ++ r;
        }
    }
    sort(p + 1 , p + n + 1);
    int res = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        int j = i;
        while (j <= n && p[i] == p[j]) {
            ++ j;
        }
        int k = j - i;
        while (k > 0) {
            res = (long long)res * (k --) % Q;
        }
        i = j - 1;
    }
    cout << res << endl;
}