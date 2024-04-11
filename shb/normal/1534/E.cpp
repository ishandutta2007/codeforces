#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, k;

int need[510];
int a[510][510];
int cnt[510], sub[510];
pii fuck[510];

void print(int ans) {
    int sum_1 = ans * k;
    for (int i = 1; i <= n; i++) {
        need[i] = 1;
    }
    sum_1 -= n;
    int t = sum_1 / (2 * n);
    sum_1 %= (2 * n);
    for (int i = 1; i <= n; i++) {
        need[i] += 2 * t;
    }
    assert(sum_1 % 2 == 0);
    for (int i = 1; i <= sum_1 / 2; i++) {
        need[i] += 2;
    }
    for (int i = 1; i <= n; i++) {
        fuck[i] = pii(need[i], i);
    }
    int xor_sum = 0;
    for (int i = 1; i <= ans; i++) {
        sort(fuck + 1, fuck + n + 1);
        reverse(fuck + 1, fuck + n + 1);
        printf("?");
        for (int j = 1; j <= k; j++) {
            printf(" %d",fuck[j].second);
            fuck[j].first--;
        }
        puts("");
        fflush(stdout);
        int ret;
        scanf("%d",&ret);
        xor_sum ^= ret;
    }
    printf("! %d\n",xor_sum);
    fflush(stdout);
}

int main() {
    scanf("%d%d",&n,&k);
    if (n % 2 == 1 && k % 2 == 0) {
        puts("-1");
        fflush(stdout);
        return 0;
    }
    for (int ans = 1; ans <= 500; ans++) {
        for (int i = 0; i <= 500; i++) cnt[i] = 0;
        int sum_1 = ans * k;
        if (sum_1 % 2 != n % 2) continue;
        //printf("check %d\n",ans);
        for (int i = 1; i <= n; i++) {
            need[i] = 1;
        }
        sum_1 -= n;
        int t = sum_1 / (2 * n);
        sum_1 %= (2 * n);
        for (int i = 1; i <= n; i++) {
            need[i] += 2 * t;
        }
        assert(sum_1 % 2 == 0);
        for (int i = 1; i <= sum_1 / 2; i++) {
            need[i] += 2;
        }
        for (int i = 1; i <= n; i++) {
            cnt[need[i]]++;
        }
        int mx = need[1];
        for (int i = 1; i <= ans; i++) {
            int remain = k;
            for (int j = mx; j >= mx - 3 && j > 0; j--) {
                sub[j] = min(remain, cnt[j]);
                remain -= sub[j];
                if (remain == 0) break;
            }
            for (int j = mx; j >= mx - 3 && j > 0; j--) {
                cnt[j] -= sub[j];
                cnt[j - 1] += sub[j];
            }
            while(cnt[mx] == 0) mx--;
        }
        if (cnt[0] == n) {
            print(ans);
            return 0;
        }
    }
    puts("-1");
    fflush(stdout);
}