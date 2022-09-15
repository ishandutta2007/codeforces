/**
* BE CAREFUL!! I have define int li
*/

//#define _GLIBCXX_DEBUG

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <bitset>
#include <map>
#include <cassert>
#include <memory.h>
#include <limits>
#include <numeric>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();


#define FILENAME "souvenir"

int main(){
    string s = FILENAME;
#ifdef DEBUG
    freopen("/Users/RiaD/Contests/Contests/input", "r", stdin);
    //freopen("output", "w", stdout);
    //cout<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    cout.sync_with_stdio(0);
    cout.precision(20);
    cout << fixed;
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
#ifdef DEBUG
    cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
    return 0;
}
typedef struct item * pitem;
struct item {
    int prior, value, cnt, sum;
    bool rev;
    pitem l, r;

    item(int val): prior(rand()), value(val), cnt(1), l(0), r(0), rev(false), sum(val) {

    }
};

int cnt (pitem it) {
    return it ? it->cnt : 0;
}

int sum(pitem it) {
    return it ? it->sum : 0;
}

void upd_cnt (pitem it) {
    if (it) {
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
        it->sum = sum(it->l) + sum(it->r) + it->value;
    }
}

void push (pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}

void reverse (pitem t) {
    if(t) {
        t->rev ^= true;
    }
}

void output (pitem t) {
    if (!t)  return;
    push (t);
    output (t->l);
    printf ("%d ", t->value);
    output (t->r);
}

void solve() {
    int n, q;
    cin >> n >> q;
    pitem root = nullptr;
    for(int i = 0; i < n; ++i) {
        merge(root, root, new item(1));
    }

    for(int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if(t == 1) {

            //cout << "new" << endl;
            int pos;
            cin >> pos;
            pitem l, r;
            split(root, l, r, pos, 0);
            assert(cnt(l) == pos);
            reverse(l);

            root = nullptr;
            while(cnt(l) && cnt(r)) {
                pitem l1, r1;
                split(l, l1, l, 1, 0);
                split(r, r1, r, 1, 0);
                l1->value += r1->value;
                //cout << "ho" << l1->value << endl;
                l1->sum += r1->sum;
                upd_cnt(l1);
                merge(root, root, l1);
            }
            merge(root, root, l);
            merge(root, root, r);


        }
        else {
            int l, r;
            cin >> l >> r;
            pitem L,M,R;

            split(root, root, R, r);


            split(root, L, M, l);

            cout << sum(M) << "\n";

            merge(root, L, M);
            merge(root, root, R);
        }
    }
}