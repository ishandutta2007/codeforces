#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

string s, ans;
int n;
char ch;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> n >> s;
    ans = s;
    for (int i = 0; i < n; i++) {
        ch = s[0];
        for (int j = 1; j < n; j++)
            s[j - 1] = s[j];
        s[n - 1] = ch;
        for (int q = 0; q < 10; q++) {
            for (int j = 0; j < n; j++) {
                if (s[j] == '9') s[j] = '0';
                else s[j]++;
            }
            //cout << s << "\n";
            if (s < ans)
                ans = s;
        }
    }

    cout << ans;

    //return 0;
}