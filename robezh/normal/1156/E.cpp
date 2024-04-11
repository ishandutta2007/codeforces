#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
const int N = (int)2e5 + 50, INF = (int)1e9;

int n;
int num[N];
int lm[N], rm[N];
int loc[N];
ll res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> num[i], loc[num[i]] = i;

    stack<P> S;
    S.push({INF, 0});
    for(int i = 1; i <= n; i++) {
        while(!S.empty() && S.top().first < num[i]) S.pop();
        lm[i] = S.top().second + 1;
        S.push({num[i], i});
    }
    while(!S.empty()) S.pop();
    S.push({INF, n + 1});
    for(int i = n; i >= 1; i--) {
        while(!S.empty() && S.top().first < num[i]) S.pop();
        rm[i] = S.top().second - 1;
        S.push({num[i], i});
    }
//    for(int i = 1; i <= n; i++) cout << i << ": " << lm[i] << ", " << rm[i] << endl;
    for(int i = 1; i <= n; i++) {
        if(i - lm[i] <= rm[i] - i) {
            for(int j = lm[i]; j < i; j++) {
                int lc = loc[num[i] - num[j]];
                if(i < lc && lc <= rm[i]) res ++;
            }
        }
        else {
            for(int j = i + 1; j <= rm[i]; j++) {
                int lc = loc[num[i] - num[j]];
                if(lm[i] <= lc && lc < i) res++;
            }
        }
    }
    cout << res << endl;
}