#include <algorithm>
#include <vector>
#include <bitset>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef unsigned int uint;

struct mset
{
    uint arr[125];
    mset()
    {
        memset(arr, 0, sizeof(arr));
    }
    void clear()
    {
        memset(arr, 0, sizeof(arr));
    }
};

//typedef bitset< 4000 > mset;

const int MAXN = 3000;
char buf[MAXN];
int n;
uint arr[MAXN];
mset tmp;
mset set_pos[MAXN];
bool has[MAXN];
double all_time = 0.;

void
construct_bitset(char *buf, mset &ans, int jd)
{
    int len = strlen(buf);
    for (int i = 0, j = len - 1; i < len; ++i, --j) {
        arr[i] = buf[j] - '0';
    }
    ans.clear();
    /*for (int i = 0; i < 4000; ++i) {
        ans[i] = 0;
    }*/
    clock_t cur_time = clock();
    int pos = 0;
    int id = len - 1;
    while (true) {
        while (id >= 0 && arr[id] == 0) --id;
        if (id < 0) break;
        unsigned long long val = 0;
        for (int i = id; i >= 0; --i) {
            val = (val * 10 + arr[i]);
            arr[i] = val >> 32;
            val = (val & ((1ull << 32) - 1));
        }
        ans.arr[pos] = val;
        //ans.arr[pos / 32] |= (val << (pos & 31));
        //ans[pos] = val;
        ++pos;
    }
    ans.arr[(2000 + jd) / 32] |= (1 << ((2000 + jd) & 31));
    //ans[2000 + id] = 1;
    all_time += (clock() - cur_time + 0.) / CLOCKS_PER_SEC;
}

int
main()
{
    scanf("%d", &n);
    for (int i = 0; i < 2000; ++i) {
        has[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        scanf(" %s", buf);
        construct_bitset(buf, tmp, i);
        int j = 0;
        while (true) {
            while (j < 2000 && !(tmp.arr[j / 32] & (1u << (j & 31)))) {
                ++j;
            }
            if (j == 2000) {
                vector< int > res;
                while (j < 2000 + i) {
                    if (tmp.arr[j / 32] & (1u << (j & 31))) {
                        res.push_back(j - 2000);
                    }
                    ++j;
                }
                printf("%lu", res.size());
                for (auto x : res) {
                    printf(" %d", x);
                }
                puts("");
                break;
            } else {
                if (!has[j]) {
                    has[j] = 1;
                    //set_pos[j] = tmp;
                    memcpy(set_pos[j].arr, tmp.arr, sizeof(tmp.arr));
                    puts("0");
                    break;
                } else {
                    for (int it = j / 32; it < 125; ++it) {
                        tmp.arr[it] ^= set_pos[j].arr[it];
                    }
                    //tmp ^= set_pos[j];
                }
            }
        }
    }
    //fprintf(stderr, "Time in get %.10lf\n", all_time);
    return 0;
}