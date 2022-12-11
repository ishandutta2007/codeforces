#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 340;
const ll INF = 1e9;
const ll md = 1e9 + 7;
const ll o720 = 301388891;

string s, k, t;
bool u[N];
int a[N], b[N], kp, c[N];

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //cout << (o720 * 720ll) % md << "\n";

    cin >> s >> k;
    for (int i = 0; i < s.length(); i++)
        a[s[i] - 'A']++;
    for (int i = 0; i < k.length(); i++)
        b[k[i] - 'A']++;

    for (int i = 0; i < 26; i++) {
        if (a[i] < b[i]) {
            for (int j = 0; j < b[i] - a[i]; j++)
                t += char('A' + i);
        }
        if (a[i] > b[i]) {
            kp += a[i];
            u[i] = true;
        }
    }

    sort(t.begin(), t.end());
    int cur = 0;
    int m = t.length();

    // cout << t << "\n";

    printf("%d\n", m);

    for (int i = 0; i < s.length(); i++) 
        if (a[s[i] - 'A'] > b[s[i] - 'A']) 
            if (t[cur] < s[i] || b[s[i] - 'A'] == c[s[i] - 'A']) {
                a[s[i] - 'A']--;
                s[i] = t[cur++];
                a[s[i] - 'A']++;
                if (cur == m) {
                    printf("%s\n", s.c_str());
                    return 0;
                }
            } else {
                c[s[i] - 'A']++;
            }
    
    printf("%s\n", s.c_str());
    return 0;
}