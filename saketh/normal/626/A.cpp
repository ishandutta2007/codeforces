#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> str;

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int vert = 0, horiz = 0;

            for (int k = i; k <= j; k++) {
                if (str[k] == 'U') vert++;
                else if(str[k] == 'D') vert--;
                else if(str[k] == 'L') horiz--;
                else horiz++;
            }

            if (vert == 0 && horiz == 0)
                ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}