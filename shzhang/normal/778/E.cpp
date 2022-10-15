#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
//
using namespace std;

#define access(i, dig) (nums[i][dig] == 0 && (dig) <= max(numlen[i], artlen) ? 10 : nums[i][dig])

char tmp[1005];
char artifact[1005];
int nums[1005][1005];
int f[1005][1005];
int numlen[1005];
int rnk[1005];
int c[15];

int n;
int curdigit;

bool cmp(int a, int b)
{
    if (nums[a][curdigit] != nums[b][curdigit])
        return nums[a][curdigit] < nums[b][curdigit];
    return rnk[a] < rnk[b];
}

int main()
{
    scanf("%s", tmp + 1); int artlen = strlen(tmp + 1);
    for (int i = 0; i <= 1003; i++) artifact[i] = '0';
    for (int i = artlen; i >= 1; i--) {
        artifact[artlen - i + 1] = tmp[i];
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", tmp + 1);
        numlen[i] = strlen(tmp + 1);
        for (int j = numlen[i]; j >= 1; j--) {
            nums[i][numlen[i] - j + 1] = tmp[j] - '0';
        }
    }
    for (int i = 0; i <= 1002; i++) {
        for (int j = 0; j <= 1002; j++) {
            f[i][j] = -2000000000;
        }
    }
    f[0][0] = 0;
    int digfreq[15];
    int orig_digfreq[15];
    for (int i = 0; i < 10; i++) scanf("%d", c + i);
    /* REMEMBER TO FIX CURDIGIT LIMIT AFTER FINISHING DEBUGGING */
    for (curdigit = 0; curdigit <= 1000; curdigit++) {
        vector<int> num_ids;
        for (int i = 1; i <= n; i++) num_ids.push_back(i);
        sort(num_ids.begin(), num_ids.end(), cmp);
        for (int i = 0; i < n; i++) {
            rnk[num_ids[i]] = i;
        }
        reverse(num_ids.begin(), num_ids.end());
        for (int i = 0; i <= 10; i++) orig_digfreq[i] = 0;
        for (int i = 1; i <= n; i++) {
            //if (nums[i][curdigit+1] == 0 && curdigit + 1 <= numlen[i])
                orig_digfreq[access(i, curdigit+1)]++;
            //else
            //    orig_digfreq[nums[i][curdigit+1]]++;
        }
        for (int newd = 0; newd < 10; newd++) {
            int new_carry_cnt = 0;
            for (int i = 0; i <= 10; i++) digfreq[i] = orig_digfreq[i];
            for (int i = 9; i >= 10 - newd; i--) new_carry_cnt += digfreq[i];
            if (artifact[curdigit+1] != '?' && artifact[curdigit+1] - '0' != newd) continue;
            if (newd == 0 && curdigit + 1 == artlen) continue;
            //printf("curdigit %d newd %d\n", curdigit, newd);
            //for (int i = 0; i <= 10; i++) {
            //    printf("%d ", digfreq[i]);
            //}
            //printf("\n");
            int new_cost_gain = 0;
            if (newd == 0) {
                for (int i = 1; i <= 10; i++) new_cost_gain += digfreq[i] * c[i%10];
            } else {
                for (int i = 0; i <= 10; i++) new_cost_gain += digfreq[i] * c[(i + newd) % 10];
            }
            for (int carry_cnt = 0; carry_cnt <= n; carry_cnt++) {
                if (carry_cnt) {
                    int numid = num_ids[carry_cnt - 1];
                    int dec_digit = access(numid, curdigit+1);
                    int inc_digit = nums[numid][curdigit+1] + 1;
                    digfreq[dec_digit]--;
                    digfreq[inc_digit]++;

                    //for (int i = 0; i <= 10; i++) {
                    //    printf("%d ", digfreq[i]);
                    //}
                    //printf("\n");

                    if (dec_digit != 10 && dec_digit >= 10 - newd) new_carry_cnt--;
                    if (inc_digit >= 10 - newd) new_carry_cnt++;

                    if (dec_digit != 0 || newd != 0) new_cost_gain -= c[(dec_digit + newd) % 10];
                    new_cost_gain += c[(inc_digit + newd) % 10];
                    //printf("new_carry_cnt %d new_cost_gain %d\n", new_carry_cnt, new_cost_gain);
                }
                //fprintf(stderr, "UPDATE %d %d %d %d from %d %d\n", newd, curdigit + 1, new_carry_cnt, f[curdigit][carry_cnt] + new_cost_gain, curdigit, carry_cnt);
                f[curdigit + 1][new_carry_cnt] = max(f[curdigit + 1][new_carry_cnt],
                    f[curdigit][carry_cnt] + new_cost_gain);
            }
        }
    }
    printf("%d", f[1001][0]);
    return 0;
}