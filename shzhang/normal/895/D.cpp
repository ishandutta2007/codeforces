#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000000007
#define ll long long
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

char a[1000005];
char b[1000005];

int n;
int pfreq[26];
int freq[26];
int factorial[1000005];
int inv_factorial[1000005];

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

int work(char* s)
{
    int ans = 0;
    for (int i = 0; i < 26; i++) freq[i] = pfreq[i];
    int all_invs = 1;
    for (int i = 0; i < 26; i++) all_invs = mul(all_invs, inv_factorial[freq[i]]);
    for (int i = 0; i < n; i++) {
        /* all characters before the ith are the same */
        for (int j = 0; j + 'a' < s[i]; j++) {
            ans += mul(mul(all_invs, freq[j]), factorial[n-i-1]);
            if (ans >= MOD) ans -= MOD;
        }
        all_invs = mul(all_invs, freq[s[i] - 'a']);
        freq[s[i] - 'a']--;
        if (freq[s[i] - 'a'] < 0) break;
    }
    return ans;
}

int main()
{
    scanf("%s%s", a, b);
    n = strlen(a);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) factorial[i] = mul(i, factorial[i-1]);
    inv_factorial[n] = fpow(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) inv_factorial[i] = mul(inv_factorial[i+1], i+1);
    for (int i = 0; i < n; i++) pfreq[a[i] - 'a']++;
    int ans_B = work(b);
    int ans_A = work(a);
    //int ans_A = 0;
    //printf("%d %d\n", ans_A, ans_B);
    printf("%d", (((ans_B - ans_A - 1) % MOD) + MOD) % MOD);
    return 0;
}