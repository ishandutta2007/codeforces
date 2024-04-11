#include <iostream>
#include <cstring>
using namespace std;
long long t, n, f[200], exist[200];
char s[200005], Q[27];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> s; n = strlen(s);
        fill(f + 'a' - 1, f + 'z' + 1, 0);
        fill(exist + 'a' - 1, exist + 'z' + 1, 0);
        for(int i=0; i<n; i++) f[s[i]]++;
        int r = 0;
        for(int i=0; i<n; i++) {
            if (!exist[s[i]]) while (r && Q[r] <= s[i] && f[Q[r]]) exist[Q[r--]] = false;
            f[s[i]]--;
            if (!exist[s[i]]) {
                Q[++r] = s[i];
                exist[s[i]] = true;
            }
        }
        for(int i=1; i<=r; i++) cout << Q[i];
        cout << '\n';
    }
}