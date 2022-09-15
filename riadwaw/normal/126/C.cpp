#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;
void solve();

#define mp make_pair
#define pb push_back

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
char s[4020][4020];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        reverse(s[i], s[i] + n);
    }
    int revgor[4020], revvert[4020];

    int ans = 0;

    memset(revgor, 0, sizeof (revgor));
    memset(revvert, 0, sizeof (revvert));
    for (int sum = 0; sum < n - 1; ++sum) {
        for (int i = 0; i <= sum; ++i) {
            int j = sum - i;
            if ((s[i][j] + revgor[i] + revvert[j]) % 2) {
                ++ans;
                //cerr<<i<<' '<<j<<ans<<endl;
                revgor[i] = !revgor[i];
                revvert[j] = !revvert[j];
            }


        }
    }


    for (int i = 0; i < n; ++i) {
        s[i][n-1-i] += revvert[n-1-i] + revgor[i];
        //cerr<<s[i][n-1-i];
    }
    //cerr<<endl;

    memset(revgor, 0, sizeof (revgor));
    memset(revvert, 0, sizeof (revvert));
    for (int sum = 2 * n - 2; sum > n - 1; --sum) {
        for (int i = 0; i <= sum; ++i) {
            int j = sum - i;
                        if(j>=n)
                            continue;
            if ((s[i][j] + revgor[i] + revvert[j]) % 2) {
                ++ans;
                //cerr<<i<<' '<<j<<ans<<endl;
                revgor[i] = !revgor[i];
                revvert[j] = !revvert[j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        s[i][n-1-i] += revvert[n-1-i] + revgor[i];

    }

    for (int i = 0; i < n; ++i) {
        if (s[i][n-1-i] % 2){
            ++ans;
            //cerr<<i<<' '<<(n-i-1)<<ans<<endl;
        }
    }

    cout << ans;
}