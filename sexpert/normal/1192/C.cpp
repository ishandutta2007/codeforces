#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int SIZE = 64;
const ll MOD = 998244353;
//abcdefghijklmnopABCDEFGHIJKLMNOP
//abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
const string alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
ll cnt[15][260][260], sum[260][260][260], cum[260][260];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<string> seen;
    while(n--) {
        string s;
        cin >> s;
        int m = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        if(seen.count(t))
            continue;
        seen.insert(s);
        cnt[m][(int)s[0]][(int)s[m - 1]]++;
        if(s != t)
            cnt[m][(int)s[m - 1]][(int)s[0]]++;
    }
    ll ways = 0;
    for(int sz = 3; sz <= 10; sz++) {
        for(int i1 = 0; i1 < SIZE; i1++) {
            for(int i2 = i1; i2 < SIZE; i2++) {
                for(int i3 = i2; i3 < SIZE; i3++) {
                    int x = alph[i1], y = alph[i2], z = alph[i3];
                    sum[x][y][z] = 0;
                    for(auto c : alph) {
                        ll a = cnt[sz][x][c] * cnt[sz][y][c] * cnt[sz][z][c];
                        sum[x][y][z] = (sum[x][y][z] + a) % MOD;
                    }
                    sum[x][z][y] = sum[y][z][x] = sum[y][x][z] = sum[z][x][y] = sum[z][y][x] = sum[x][y][z];
                }
            }
        }
        for(int i1 = 0; i1 < SIZE; i1++) {
            int c1 = alph[i1];
            for(int i2 = i1; i2 < SIZE; i2++) {
                int c2 = alph[i2];
                for(int i3 = i2; i3 < SIZE; i3++) {
                    int c3 = alph[i3];
                    for(int i4 = i3; i4 < SIZE; i4++) {
                        int c4 = alph[i4];
                        ll a = (sum[c1][c2][c3] * sum[c1][c2][c4]) % MOD, b = (sum[c1][c3][c4] * sum[c2][c3][c4]) % MOD;
                        ll tot = (a * b) % MOD;
                        if(i1 == i4)
                            ways += tot;
                        else if(i1 == i3)
                            ways += 4LL*tot;
                        else if(i1 == i2) {
                            if(i3 == i4)
                                ways += 6LL*tot;
                            else
                                ways += 12LL*tot;
                        }
                        else {
                            if(i2 == i4)
                                ways += 4LL*tot;
                            else if(i2 == i3)
                                ways += 12LL*tot;
                            else {
                                if(i3 == i4)
                                    ways += 12LL*tot;
                                else
                                    ways += 24LL*tot;
                            }
                        }
                        ways %= MOD;
                    }
                }
            }
        }
    }
    cout << ways << '\n';
}