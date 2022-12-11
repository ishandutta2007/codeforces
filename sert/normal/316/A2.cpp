#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

typedef int ll;

string s;
int kol, k0;
int ans = 1;
bool u[100];

int main() {

    //freopen("a.in", "r", stdin);

    ///Test: #33, : 0 ., : 0 ,  : 0,   : 0, : CRASHED

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '?')
            if (i)
                k0++;
            else
                ans *= 9;

        if (s[i] >= 'A' && s[i] <= 'J') {
            if (!u[s[i] - 'A']) {
                u[s[i] - 'A'] = true;
                if (i == 0)
                    ans *= 9;
                else
                    ans *= (10 - kol);
                kol++;
            }
        }
    }

    cout << ans;
    for (int i = 0; i < k0; i++)
        printf("0");

    return 0;
}