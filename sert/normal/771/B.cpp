#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;

string s[N];
int len;

int main() {
    init();

    for (char c1 = 'A'; c1 <= 'Z'; c1++)
    for (char c2 = 'a'; c2 <= 'z'; c2++) {
        s[len].push_back(c1);
        s[len].push_back(c2);
        len++;
    }

    int n, k;
    cin >> n >> k;
    string t;

    for (int i = 0; i < n - k + 1; i++) {
        cin >> t;
        if (t == "NO") {
            s[k + i - 1] = s[i];
        }
    }

    for (int i = 0; i < n; i++)
        cout << s[i] << " ";

    return 0;
}