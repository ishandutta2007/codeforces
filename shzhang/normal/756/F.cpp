#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MOD 1000000007
#define ll long long

struct mi {
    int val;
    mi() : val(0) {}
    mi(int v) : val(v) {}
};

mi operator+(mi a, mi b)
{
    mi ans; ans.val = a.val + b.val;
    if (ans.val >= MOD) ans.val -= MOD;
    return ans;
}

mi operator-(mi a, mi b)
{
    mi ans; ans.val = a.val - b.val;
    if (ans.val < 0) ans.val += MOD;
    return ans;
}

mi operator*(mi a, mi b)
{
    mi ans; ans.val = ((ll)a.val * (ll)b.val) % MOD;
    return ans;
}

mi fpow(mi base, int exponent)
{
    mi ans = 1;
    mi cur = base;
    while (exponent) {
        if (exponent & 1) ans = ans * cur;
        cur = cur * cur; exponent >>= 1;
    }
    return ans;
}

mi operator/(mi a, mi b)
{
    return a * fpow(b, MOD - 2);
}

struct num {
    mi val, nxtdig;
};

num concat(num a, num b)
{
    num result;
    result.val = a.val * b.nxtdig + b.val;
    result.nxtdig = a.nxtdig * b.nxtdig;
    return result;
}

num deconcat(num remove, num from)
{
    from.val = from.val - remove.val * (from.nxtdig / remove.nxtdig);
    from.nxtdig = from.nxtdig / remove.nxtdig;
    return from;
}

char s[100005];
int stk[100005]; int stknxt = 0;
int nxtbrc[100005];
int prebrc[100005];
int nxtplus[100005];
int minuspsum[100005];

num expression(int l, int r);

num number(int l, int r)
{
    num cur; cur.val = 0; cur.nxtdig = 1;
    for (int i = l; i <= r; i++) {
        cur.val = cur.val * 10; cur.val = cur.val + (int)(s[i] - '0');
        cur.nxtdig = cur.nxtdig * 10;
    }
    return cur;
}

int number2(int l, int r)
{
    int val = 0;
    for (int i = l; i <= r; i++) {
        val = ((ll)val * 10LL + (ll)(s[i] - '0')) % (MOD - 1);
    }
    //printf("%d %d: %d\n", l, r, val);
    return val;
}

num alldig[100005];

num seqraw(mi k, int k_m2, mi x)
{
    num ans;
    ans.val = (((fpow(x, k_m2+1)) - 1) / (x - 1) - k - 1) / (x - 1);
    ans.nxtdig = fpow(x, k_m2);
    return ans;
}

num seq(int l, int r)
{
    num cur; cur.val = 0; cur.nxtdig = 1;
    for (int i = 1; i <= r - l; i++) {
        cur = concat(cur, alldig[i]);
    }
    num intv = number(l, r);
    num last = seqraw(intv.val, number2(l, r), intv.nxtdig);
    if (r > l) {
        int v = 1;
        for (int i = 1; i <= r - l; i++) v = ((ll)v * 10LL) % (MOD - 1LL);
        v--; if (v < 0) v += MOD;
        last = deconcat(seqraw(fpow(10, r - l) - 1, v, intv.nxtdig), last);
    }
    cur = concat(cur, last);
    return cur;
}

num term(int l, int r)
{
    //printf("term %d %d\n", l, r);
    if (s[r] == ')') {
        int preb = prebrc[r];
        num val = expression(preb + 1, r - 1);
        int repeats2 = number2(l, preb - 1);
        //printf("!%d\n", val.nxtdig.val);
        num ans; ans.nxtdig = fpow(val.nxtdig, repeats2);
        if (val.nxtdig.val == 1) {
            ans.val = val.val * number(l, preb - 1).val;
        } else {
            ans.val = val.val * ((fpow(val.nxtdig, repeats2) - 1) / (val.nxtdig - 1));
        }
        return ans;
    } else if (minuspsum[l] != minuspsum[r]) {
        int dpos = 0;
        for (int i = l; i <= r; i++) if (s[i] == '-') dpos = i;
        return concat(number(l, dpos - 1), deconcat(seq(l, dpos - 1), seq(dpos + 1, r)));
    } else {
        return number(l, r);
    }
}

num expression(int l, int r)
{
    //printf("expression %d %d\n", l, r);
    if (nxtplus[l] > r) {
        //printf("%d %d: %d\n", l, r, term(l, r).val.val);
        return term(l, r);
    }
    return concat(term(l, nxtplus[l] - 1), expression(nxtplus[l] + 1, r));
}

int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') stk[stknxt++] = i;
        if (s[i] == ')') {
            int pre = stk[--stknxt];
            nxtbrc[pre] = i;
            prebrc[i] = pre;
        }
        minuspsum[i] = minuspsum[i-1] + (s[i] == '-');
    }
    nxtplus[n+1] = n + 1;
    for (int i = n; i >= 1; i--) {
        if (s[i] == '+') nxtplus[i] = i;
        else if (s[i] == '(') nxtplus[i] = nxtplus[nxtbrc[i]];
        else nxtplus[i] = nxtplus[i+1];
    }
    mi cur = 9;
    int cur2 = 9;
    mi curpwr = 10;
    mi pcur; int pcur2 = 0;
    for (int i = 1; i <= 100000; i++) {
        if (i == 1) {
            alldig[i] = seqraw(cur, cur2, curpwr);
        } else {
            alldig[i] = deconcat(seqraw(pcur, pcur2, curpwr), seqraw(cur, cur2, curpwr));
        }
        /*if (i <= 5) {
            printf("%d %d\n", alldig[i].val.val, alldig[i].nxtdig.val);
        }*/
        pcur = cur; pcur2 = cur2;
        cur = cur * 10 + 9;
        cur2 = ((ll)cur2 * (ll)10 + 9LL) % (MOD - 1);
        curpwr = curpwr * 10;
    }

    num ans = expression(1, n);
    printf("%d", ans.val.val);

    //num val = concatraw(11, 11, 100);
    //printf("%d %d\n", val.val.val, val.nxtdig.val);

    return 0;
}