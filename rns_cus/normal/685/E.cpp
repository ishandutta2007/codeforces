#include <iostream>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <string>
#include <assert.h>
#include <iterator>
#include <bitset>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::min;
using std::abs;
using std::max;

using std::sort;
using std::generate;
using std::min_element;
using std::max_element;

#define size_t uint32_t

struct Req {
    size_t L;
    size_t R;
    size_t S;
    size_t T;
    size_t ID;
};

struct Edge {
    size_t v;
    size_t u;
    size_t prev1;
    size_t prev2;
    size_t next1;
    size_t next2;
};

const size_t MAXQ = 200000;
const size_t MAXN = 1000;
const size_t MAXM = 200000;

char answers[MAXQ];
Edge list[MAXM];
vector<size_t> last[MAXN];

std::bitset<MAXN> masks_r[MAXM / 2 + 10];
std::bitset<MAXN> masks_l[MAXM / 2 + 10];

void solve_layer(vector<Req>& requests, size_t l, size_t m, size_t r) {
    bool has = false;
    for (size_t i = 0; i != requests.size(); ++i)
        has or_eq (requests[i].L <= m - 1 and requests[i].R >= m);
    if (not has)
        return;
    
    for (size_t i = 0; i != r - m; ++i) {
        masks_r[i] = std::bitset<MAXN>();
        if (list[m + i].prev1 >= m and list[m + i].prev1 != std::numeric_limits<size_t>::max())
            masks_r[i] |= masks_r[list[m + i].prev1 - m];
        if (list[m + i].prev2 >= m and list[m + i].prev2 != std::numeric_limits<size_t>::max())
            masks_r[i] |= masks_r[list[m + i].prev2 - m];

        masks_r[i][list[m + i].v] = true;
        masks_r[i][list[m + i].u] = true;
    }
    
    for (size_t z = 0; z != m - l; ++z) {
        size_t i = (m - l) - 1 - z;
        masks_l[i] = std::bitset<MAXN>();
        
        if (list[l + i].next1 < m)
            masks_l[i] |= masks_l[list[l + i].next1 - l];
        if (list[l + i].next2 < m)
            masks_l[i] |= masks_l[list[l + i].next2 - l];
        masks_l[i][list[l + i].v] = true;
        masks_l[i][list[l + i].u] = true;
    }

    for (size_t i = 0; i != requests.size();)
        if (requests[i].L <= m - 1 and requests[i].R >= m) {
            answers[requests[i].ID] = (masks_r[requests[i].R - m] & masks_l[requests[i].L - l]).any();
            std::swap(requests[i], requests.back());
            requests.pop_back();
        } else {
            ++i;
        }
}

void solve(vector<Req>& requests, size_t l, size_t r) {
    if (l == r - 1) {
        for (auto& req: requests)
            answers[req.ID] = (req.S == list[l].v or req.S == list[l].u)
                          and (req.T == list[l].v or req.T == list[l].u);
        return;
    }
    size_t m = l + (r - l) / 2;
    // [l, m), [m, r).

    solve_layer(requests, l, m, r);

    vector<Req> right;
    for (size_t i = 0; i != requests.size();)
        if (requests[i].L >= m) {
            right.push_back(requests[i]);
            std::swap(requests[i], requests.back());
            requests.pop_back();
        } else {
            ++i;
        }

    requests.shrink_to_fit();
    solve(requests, l, m);
    solve(right, m, r);
}

int main() {
    size_t n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    assert(n <= MAXN);
    assert(q <= MAXQ);
    assert(m <= MAXM);
    
    std::fill(answers, answers + q, 16);
    
    for (size_t i = 0; i != m; ++i) {
        scanf("%d %d", &list[i].v, &list[i].u);
        --list[i].v, --list[i].u;
        list[i].prev1 = list[i].prev2 = list[i].next1 = list[i].next2 = std::numeric_limits<size_t>::max();
        
        if (not last[list[i].v].empty()) {
            list[i].prev1 = last[list[i].v].back();
            
            if (list[last[list[i].v].back()].v == list[i].v)
                list[last[list[i].v].back()].next1 = i;
            else {
                list[last[list[i].v].back()].next2 = i;
            }
        }

        if (not last[list[i].u].empty()) {
            list[i].prev2 = last[list[i].u].back();
            
            if (list[last[list[i].u].back()].v == list[i].u)
                list[last[list[i].u].back()].next1 = i;
            else {
                list[last[list[i].u].back()].next2 = i;
            }
        }
        
        last[list[i].v].push_back(i);
        last[list[i].u].push_back(i);
    }

    vector<Req> requests;
    for (size_t i = 0; i != q; ++i) {
        Req req;
        scanf("%d %d %d %d", &req.L, &req.R, &req.S, &req.T);
        --req.L, --req.R, --req.S, --req.T;
        req.ID = i;
        
        auto it1 = std::lower_bound(last[req.S].begin(), last[req.S].end(), req.L);
        auto it2 = std::upper_bound(last[req.T].begin(), last[req.T].end(), req.R);

        if (it1 == last[req.S].end() or it2 == last[req.T].begin())
            answers[i] = false;
        else {
            req.L = *it1;
            req.R = *std::prev(it2);
            if (req.L > req.R)
                answers[i] = false;
            else
                requests.push_back(req);
        }
    }
    
    solve(requests, 0, m);

    for (size_t i = 0; i != q; ++i) {
        printf("%s", (answers[i] ? "Yes\n" : "No\n"));
    }
    
    return 0;
}