#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int T, n, m;
char s[N], t[N];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d%s", &n, &m, s+1);

        vector<int> v;
        vector< pair<int,int> > ans;
        for (int i = 1; i <= n; i ++) if (s[i] == '(') v.push_back(i);
        for (int i = 0; i < v.size(); i ++) {
            ans.push_back( make_pair(i + 1, v[i]) );
        }
        int cnt = 0;
        for (int i = n / 2 + 1; i <= min(n, n / 2 + m - 1); i ++) {
            ans.push_back(make_pair(2 * (i - n/2), i));
        }
        printf("%d\n", ans.size());
        for (auto p: ans) {
            printf("%d %d\n", p.first, p.second);
        }
    }
}