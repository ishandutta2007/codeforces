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

#define int li



typedef struct item * pitem;
struct item {
    int prior, value, sum, cnt;
    item(int value): value(value), sum(value), cnt(1), prior(rand()), l(0), r(0) {

    }
    pitem l, r;
};



int sum(pitem it) {
    if(it) {
        return it->sum;
    }
    return 0;
}

int cnt (pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
    if (it) {
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
        it->sum = it->value + sum(it->l) + sum(it->r);
    }
}

void push (pitem it) {

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

void splitByCnt(pitem t, pitem& l, pitem& r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        splitByCnt(t->l, l, t->l, key, add),  r = t;
    else
        splitByCnt(t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}

void splitByKey(pitem t, int key, pitem& l, pitem& r) {
    if (!t)
        l = r = NULL;
    else if (key <= t->value)
        splitByKey(t->l, key, l, t->l),  r = t;
    else
        splitByKey(t->r, key, t->r, r),  l = t;
        upd_cnt (t);
}



multiset<int> toset (pitem t) {
    multiset<int> z;
    if(!t)
        return z;
    z.insert(t->value);
    auto zz = toset(t->l);
    z.insert(zz.begin(), zz.end());
    zz = toset(t->r);
    z.insert(zz.begin(), zz.end());
    return z;
}

pitem root = nullptr;

multiset<int> ms;

struct xz{
    int size;
    void insert(int v) {
        //cout << "add" << ' ' << v << endl;
        ++size;
        pitem m = new item(v);
        pitem l, r;
        splitByKey(root, v, l, r);

        merge(root, l, m);
        merge(root, root, r);

    }

    void remove(int v) {
        //cout << "remove " << v << endl;
        --size;
        pitem l, m, r;
        splitByKey(root, v, l, r);
        splitByKey(r, v + 1, m, r);
        if(m == nullptr){
            while(true);
        }
        merge(m, m->l, m->r);
        pitem tmp;
        merge(tmp, l, m);
        merge(root, tmp, r);
    }

    int sumFirst(int v) {

        //cout << v << ' ' << size << endl;

        assert(v <= size);
        pitem l, r;
        splitByCnt(root, l, r, v, 0);
        if(cnt(l) < v) while(true);
        if(cnt(l) > v) exit(1);
        int res = sum(l);
        merge(root, l, r);
        //if(ms != toset(root))while(true);
        return res;
    }
};

xz XZ;

vector<int> v[101010];

vector<int> cnt2group[101010];

int buyed[101010];
void solve() {


    long long moneySpend = 0;
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);

        cnt2group[v[a].size()].push_back(a);

        XZ.insert(b);

    }


    for(int i = 0; i <= 100000; ++i) {
        sort(v[i].begin(), v[i].end());
    }

    long long ans = 1000000000000000000LL;


    for (int peopleBought = n; peopleBought > 0; --peopleBought) {
        int numCheap = peopleBought;
        for (int gr: cnt2group[peopleBought]) {
            assert(int(v[gr].size()) - peopleBought >= 0);

            int needBuy = (v[gr].size() - peopleBought) + 1;
            //if(needBuy != buyed[gr]) {
            ++buyed[gr];

            assert(needBuy - 1 < v[gr].size());
            moneySpend += v[gr][needBuy - 1];
            XZ.remove(v[gr][needBuy - 1]);
            //}
            numCheap -= needBuy;

        }

        if(numCheap <= 0) {
            ans = min(ans, moneySpend);
            break;
        }
        else {
            ans = min(ans, moneySpend + XZ.sumFirst(numCheap));
        }


    }

    cout << ans;

}