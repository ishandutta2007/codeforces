#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long
#define lowbit(x) ((x)&(-(x)))

int n, m;
char a[500005];
char b[500005];
char S[1000005];
char tmp[2000005];
int pre[500005];
int suf[500005];

int a_arr[500005];
int b_arr[500005];

ll pair_cnt = 0;

bool cmp1(int A, int B)
{
    return pre[A] < pre[B];
}

bool cmp2(int A, int B)
{
    return suf[A] > suf[B];
}

int rquery(int* arr, int v)
{
    int ans = 0;
    while (v) {
        ans += arr[v]; v -= lowbit(v);
    }
    return ans;
}

void modify(int* arr, int loc, int val)
{
    while (loc <= n) {
        arr[loc] += val; loc += lowbit(loc);
    }
}

int query(int* arr, int l, int r)
{
    if (l < 1) l = 1;
    if (r > n) r = n;
    return rquery(arr, r) - rquery(arr, l-1);
}

void update(int arr, int loc, int val)
{
    //printf("Update %d %d %d\n", arr, loc, val);
    if (arr == 1) {
        modify(a_arr, loc, val);
        pair_cnt += (ll)val * (ll)query(b_arr, loc, loc + m - 2);
    } else {
        modify(b_arr, loc, val);
        pair_cnt += (ll)val * (ll)query(a_arr, loc - m + 2, loc);
    }
}

int* zfunc(char* s)
{
    int N = strlen(s + 1);
    int* Z = new int[strlen(s + 1) + 10];
    int x = 1, y = 1;
    Z[1] = N;
    for (int i = 2; i <= N; i++) {
        if (i <= y) {
            Z[i] = min(Z[i - x + 1], y - i + 1);
        } else {
            Z[i] = 0;
        }
        while (i + Z[i] <= N && s[i + Z[i]] == s[1 + Z[i]]) {
            x = i; y = i + Z[i]; Z[i]++;
        }
    }
    return Z;
}

int main()
{
    int* Z;
    scanf("%d%d", &n, &m);
    scanf("%s%s%s", a + 1, b + 1, S + 1);

    for (int i = 1; i <= m; i++) tmp[i] = S[i];
    tmp[m+1] = '#';
    for (int i = 1; i <= n; i++) tmp[m+i+1] = a[i];
    Z = zfunc(tmp);
    for (int i = 1; i <= n; i++) pre[i] = Z[m+i+1];

    for (int i = 1; i <= m; i++) tmp[i] = S[m-i+1];
    for (int i = 1; i <= n; i++) tmp[m+i+1] = b[n-i+1];
    Z = zfunc(tmp);
    for (int i = 1; i <= n; i++) suf[n-i+1] = Z[m+i+1];

    /*for (int i = 1; i <= n; i++) printf("%d ", pre[i]);
    printf("\n");
    for (int i = 1; i <= n; i++) printf("%d ", suf[i]);
    printf("\n");*/

    vector<int> pre_pos; int pre_cur = 0;
    vector<int> suf_pos; int suf_cur = 0;
    for (int i = 1; i <= n; i++) pre_pos.push_back(i), suf_pos.push_back(i);
    sort(pre_pos.begin(), pre_pos.end(), cmp1);
    sort(suf_pos.begin(), suf_pos.end(), cmp2);

    for (int i = 1; i <= n; i++) update(1, i, 1);

    ll ans = 0;

    for (int left = 1; left <= n; left++) {
        int right = m - left;
        if (right <= 0) break;
        while (pre_cur < n && pre[pre_pos[pre_cur]] < left) update(1, pre_pos[pre_cur], -1), pre_cur++;
        while (suf_cur < n && suf[suf_pos[suf_cur]] >= right) update(2, suf_pos[suf_cur], 1), suf_cur++;
        ans += pair_cnt;
        //printf("%lld\n", pair_cnt);
    }
    printf("%lld", ans);
    return 0;
}