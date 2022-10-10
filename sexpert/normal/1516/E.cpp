#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 205;
const ll MOD = 1e9 + 7;
const ll fuck_you = 10000000;
ll dp[MAXN][MAXN], fac[MAXN], ifac[MAXN], inv[MAXN], ans[MAXN];
vector<ll> kys = {1, 682498929, 491101308, 76479948, 723816384, 67347853, 27368307, 625544428, 199888908, 888050723, 927880474, 281863274, 661224977, 623534362, 970055531, 261384175, 195888993, 66404266, 547665832, 109838563, 933245637, 724691727, 368925948, 268838846, 136026497, 112390913, 135498044, 217544623, 419363534, 500780548, 668123525, 128487469, 30977140, 522049725, 309058615, 386027524, 189239124, 148528617, 940567523, 917084264, 429277690, 996164327, 358655417, 568392357, 780072518, 462639908, 275105629, 909210595, 99199382, 703397904, 733333339, 97830135, 608823837, 256141983, 141827977, 696628828, 637939935, 811575797, 848924691, 131772368, 724464507, 272814771, 326159309, 456152084, 903466878, 92255682, 769795511, 373745190, 606241871, 825871994, 957939114, 435887178, 852304035, 663307737, 375297772, 217598709, 624148346, 671734977, 624500515, 748510389, 203191898, 423951674, 629786193, 672850561, 814362881, 823845496, 116667533, 256473217, 627655552, 245795606, 586445753, 172114298, 193781724, 778983779, 83868974, 315103615, 965785236, 492741665, 377329025, 847549272, 698611116};

ll _inv(ll b) {
    ll e = MOD - 2, r = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) r = (r * b) % MOD;
        b = (b * b) % MOD;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /*ll kys = 1;
    cout << "{";
    for(ll i = 1; i <= 1000000000; i++) {
        kys = (i * kys) % MOD;
        if(i % fuck_you == 0)
            cout << kys << ", ";
    }
    cout << "};" << endl;*/

    fac[0] = 1;
    for(ll i = 1; i < MAXN; i++)
        fac[i] = (i * fac[i - 1]) % MOD;

    ifac[MAXN - 1] = _inv(fac[MAXN - 1]);
    for(ll i = MAXN - 1; i >= 1; i--)
        ifac[i - 1] = (i * ifac[i]) % MOD;

    for(int i = 1; i < MAXN; i++)
        inv[i] = (ifac[i] * fac[i - 1]) % MOD;

    dp[0][0] = 1;
    for(ll m = 200; m >= 1; m--) {
        for(int n = 200; n >= 1; n--) {
            for(ll s = m; s <= 200; s++) {
                ll tot = inv[m + 1];
                for(ll k = 1; k * m <= s && k <= n; k++) {
                    ll ex = (dp[n - k][s - k * m] * tot) % MOD;
                    ex = (ex * ifac[k]) % MOD;
                    dp[n][s] = (dp[n][s] + ex) % MOD;
                    tot = (tot * inv[m + 1]) % MOD;
                }
            }
        }
    }

    /*for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }*/

    ans[0] = 1;
    int n, k;
    cin >> n >> k;
    ll cock = n / fuck_you;
    ll fac_n = kys[cock];
    for(ll x = fuck_you * cock + 1; x <= n; x++)
        fac_n = (x * fac_n) % MOD;

    ll sodomy = _inv(fac_n);
    for(int i = 1; i <= k; i++) {
        sodomy = sodomy * (n - i + 1) % MOD;
        if(i > 1) ans[i] = ans[i - 2];
        if(i <= n - 1) {
            ll ex = 0;
            ll sin = sodomy;
            for(int j = 1; j <= min(n - i, i); j++) {
                sin = (sin * (n - i - j + 1)) % MOD;
                ex = (ex + dp[j][i] * sin) % MOD;
            }

            ans[i] = (ans[i] + fac_n * ex) % MOD;
        }

        cout << ans[i] << " ";
    }
    cout << '\n';
}