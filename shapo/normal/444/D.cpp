#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

const int MAXN = 100500;
const int MAXK = 1000;

int n;
int block_cnt;
int block_sz;
int l[MAXK], r[MAXK];
char s[MAXN];
int q;
int a[MAXN], b[MAXN];
int lena[MAXN], lenb[MAXN];
char as[5], bs[5];
map< pair< int, int >, int > diff;
map< int, vector< int > > all_block_lft;
map< int, vector< int > > all_block_rght;
set< int > all_q;


int
code(const char *s, int len)
{
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        int cur_dig = (i >= len) ? 0 : s[i] - 'a' + 1;
        res = res * 27  + cur_dig;
    }
    return res;
}

int
main()
{
    scanf(" %s", s);
    n = strlen(s); 
    block_sz = min(n, int(sqrt(n + 10.) / 7 + 1.) + 1);
    block_cnt = (n + block_sz - 1) / block_sz;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf(" %s %s", as, bs);
        a[i] = code(as, strlen(as)), b[i] = code(bs, strlen(bs));
        lena[i] = strlen(as), lenb[i] = strlen(bs);
        diff[make_pair(a[i], b[i])] = diff[make_pair(b[i], a[i])] = 2 * n;
        all_q.insert(a[i]);
        all_q.insert(b[i]);
    }
    for (int id = 0; id < block_cnt; ++id) {
        int lb = id * block_sz;
        int rb = min(n - 1, (id + 1) * block_sz - 1);
        for (int fp = lb; fp <= rb; ++fp) {
            for (int cnt = 1; cnt <= n - fp && cnt <= 4; ++cnt) {
                int a_str = code(s + fp, cnt);
                set< int >::iterator s_it = all_q.find(a_str);
                if (s_it != all_q.end()) {
                    {
                        vector< int > &tmp = all_block_lft[a_str];
                        if (tmp.empty() || tmp.back() < lb) {
                            tmp.push_back(fp);
                        }
                    }
                    {
                        vector< int > &tmp = all_block_rght[a_str];
                        if (tmp.empty() || tmp.back() < lb) {
                            tmp.push_back(fp);
                        } else {
                            tmp.back() = fp;
                        }
                    }
                }
                for (int sp = fp; sp <= rb; ++sp) {
                    for (int cnt1 = 1; cnt1 <= n - sp && cnt1 <= 4; ++cnt1) {
                        int b_str = code(s + sp, cnt1);
                        map< pair< int, int >, int >::iterator it = diff.find(make_pair(a_str, b_str));
                        if (it != diff.end()) {
                            it->second = min(it->second, max(cnt, sp - fp + cnt1));
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int res = min(diff[make_pair(a[i], b[i])], diff[make_pair(b[i], a[i])]);
        for (int it = 0; it < 2; ++it) {
            vector< int > &ar = all_block_rght[a[i]];
            vector< int > &br = all_block_lft[b[i]];
            int asz = int(ar.size());
            int bsz = int(br.size());
            for (int lb = 0, rb = 0; lb < asz; ++lb) {
                while (rb < bsz && br[rb] < ar[lb]) ++rb;
                if (rb != bsz) {
                    res = min(res, max(lena[i], br[rb] - ar[lb] + lenb[i]));
                }
            }
            swap(a[i], b[i]);
            swap(lena[i], lenb[i]);
        }
        if (res > n) {
            res = -1;
        }
        printf("%d\n", res);
    }
    return 0;
}