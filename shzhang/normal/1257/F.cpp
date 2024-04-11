#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int n;

struct A {
    uint16_t xorval;
    uint8_t nums[105];
};

uint16_t high[105];
uint16_t low[105];

A high_list[16384];
vector<A> low_list;

int bwt[65536];

bool cmp(const A& x, const A& y)
{
    for (int i = 1; i <= n; i++) {
        if (x.nums[i] != y.nums[i]) {
            return x.nums[i] < y.nums[i];
        }
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        high[i] = (a >> 16);
        low[i] = (a & 0xFFFF);
    }
    for (int i = 0; i < 65536; i++) {
        bwt[i] = bwt[i>>1] + (i&1);
    }
    for (uint16_t i = 0; i < 16384; i++) {
        A& cur = high_list[i];
        for (int j = 1; j <= n; j++) {
            cur.nums[j] = bwt[high[j] ^ i];
        }
    }
    for (uint16_t i = 0; ; i++) {
        A cur;
        cur.xorval = i;
        for (int j = 1; j <= n; j++) {
            cur.nums[j] = bwt[low[j] ^ i];
        }
        low_list.push_back(cur);
        if (i == 65535) break;
    }
    sort(low_list.begin(), low_list.end(), cmp);
    for (uint16_t i = 0; i < 16384; i++) {
        for (int s = 0; s <= 30; s++) {
            A goal;
            int l = 0, r = 65535;
            bool good = true;
            for (int j = 1; j <= n; j++) {
                if (high_list[i].nums[j] > s) goto loop_end;
                goal.nums[j] = s - high_list[i].nums[j];
            }
            while (l < r) {
                int mid = (l + r) / 2;
                if (cmp(low_list[mid], goal)) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if (l > 65535) continue;
            for (int x = 1; x <= n; x++) {
                if (low_list[l].nums[x] != goal.nums[x]) {
                    good = false; break;
                }
            }
            if (good) {
                printf("%d", (i << 16) + low_list[l].xorval);
                return 0;
            }
            loop_end: ;
        }
    }
    printf("-1");
    return 0;
}