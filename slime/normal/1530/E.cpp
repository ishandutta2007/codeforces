//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 100005;
char inp[maxn];
int cnt[26];
vi res;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        scanf("%s", inp);
        memset(cnt, 0, sizeof(cnt));
        int l = strlen(inp);
        for (int j = 0; j < l; j++)
            cnt[inp[j] - 'a']++;
        res.clear();
        int flag = 0;
        for (int i = 0; i < 26; i++)
            if (cnt[i] == l) {
                for (int j = 0; j < l; j++) res.pb(i);
                flag = 1;
                break;
            }
        if (!flag) {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 1) {
                    res.pb(i); cnt[i] -= 1;
                    for (int j = 0; j < 26; j++)
                        for (int s = 0; s < cnt[j]; s++)
                            res.pb(j);
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < 26; i++) {
                if (cnt[i]) {
                    res.pb(i);
                    cnt[i] -= 1;
                    int nx = 0;
                    if (cnt[i] <= (l - 2) / 2 + 1) nx = i;
                    else {
                        for (int j = 0; j < 26; j++) {
                            if (j == i) continue;
                            if (cnt[j]) {
                                nx = j;
                                break;
                            }
                        }
                    }
                    res.pb(nx); cnt[nx] -= 1;
                    int fr = nx;
                    for (int s = 0; s < l - 2; s++) {
                        for (int j = 0; j < 26; j++) {
                            if (cnt[j]) {
                                if (fr == i && j == nx) continue;
                                if (i != nx && j == i && cnt[nx] + cnt[i] == l - 2 - s && cnt[nx]) continue;
                                res.pb(j);
                                cnt[j] -= 1;
                                fr = j;
                                break;
                            }
                        }
                    }

                    flag = 1;
                    break;
                }
            }
        } 
        for (auto v : res) {
            printf("%c", char(int('a') + v));
        }
        printf("\n");
    }
    return 0;
}