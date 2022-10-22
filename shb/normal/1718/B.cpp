#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

LL f[110];
LL s[110];
int M = 45;

int main() {
    ios::sync_with_stdio(false);
    f[0] = f[1] = 1;
    s[0] = 1;
    s[1] = 2;
    for (int i = 2; i <= M; i++) {
        f[i] = f[i - 1] + f[i - 2];
        s[i] = s[i - 1] + f[i];
        //printf("%d %lld %lld\n",i,f[i],s[i]);
    }
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        priority_queue<int> hp;
        LL sum = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            sum += tmp;
            hp.push(tmp);
        }
        int idx = -1;
        for (int i = 0; i <= M; i++) {
            if (sum == s[i]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        int last_pop = -1;
        while(idx >= 0) {
            if (hp.empty()) {
                ok = false;
                break;
            }
            int now = hp.top();
            hp.pop();
            if (now < f[idx]) {
                ok = false;
                break;
            }
            now -= f[idx];
            if (last_pop > 0) hp.push(last_pop);
            last_pop = now;
            idx--;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}