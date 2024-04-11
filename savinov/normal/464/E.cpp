#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define x first
#define y second
#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)
#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))

using namespace std;
using namespace std::rel_ops;

template <typename T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

template<class T> struct smartPtr {
    int * cnt;
    T * data;

    smartPtr(T * v = 0) {
        cnt = new int(1);
        data = v;
    }
    ~smartPtr() {
        if (!(--*cnt)) {
            delete cnt;
            delete data;
        }
    }
    smartPtr & operator=(const smartPtr<T> & r) {
        if (this->data != r.data) {
            this->~smartPtr();
            ++*(this->cnt = r.cnt);
            this->data = r.data;
        }
    }

    smartPtr(const smartPtr<T> & r) {
        cnt = r.cnt;
        data = r.data;
        ++*cnt;
    }

    T * operator->() const {
        return data;
    }

    T * operator->() {
        return data;
    }

    T & operator*() {
        return *data;
    }

    T & operator*() const {
        return *data;
    }
};


struct node {
    smartPtr<node> l, r;
    long long hash;
    long long pw;
    int zeroCount;
};

typedef smartPtr<node> inode;

inode ZERO, ONE;

inode pick(inode l, inode r) {
    inode res(new node());
    res->l = l, res->r = r;
    res->hash = l->hash * l->pw + r->hash;
    res->pw = l->pw * r->pw;
    res->zeroCount = l->zeroCount + r->zeroCount;
    return res;
}

inode build(int tl, int tr, int val) {
    if (tl == tr) {
        return val ? ONE : ZERO;
    }
    int tm = (tl + tr) >> 1;
    return pick(build(tl, tm, val), build(tm + 1, tr, val));
}

inode fillZeroes(inode v, inode zeroes, int tl, int tr, int l, int r) {
    if (l > r) {
        return v;
    }
    if (l == tl && r == tr) {
        return zeroes;
    }
    int tm = (tl + tr) >> 1;

    inode left = fillZeroes(v->l, zeroes->l, tl, tm, l, min(tm, r));
    inode right = fillZeroes(v->r, zeroes->r, tm + 1, tr, max(tm + 1, l), r);

    return pick(left, right);
}

inode setOne(inode v, int tl, int tr, int pos) {
    if (tl == tr) {
        return ONE;
    }
    int tm = (tl + tr) >> 1;
    inode left, right;
    if (pos <= tm) {
        left = setOne(v->l, tl, tm, pos);
        right = v->r;
    } else {
        left = v->l;
        right = setOne(v->r, tm + 1, tr, pos);
    }
    return pick(left, right);
}

int getZeroCount(inode v, int tl, int tr, int l, int r) {
    if (l > r) return 0;

    if (tl == l && tr == r) {
        return v->zeroCount;
    }
    int tm = (tl + tr) >> 1;

    int left = getZeroCount(v->l, tl, tm, l, min(tm, r));
    int right = getZeroCount(v->r, tm + 1, tr, max(tm + 1, l), r);

    return left + right;
}

int findKthZero(inode v, int tl, int tr, int k) {
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) >> 1;
    if (v->l->zeroCount >= k) {
        return findKthZero(v->l, tl, tm, k);
    } else {
        return findKthZero(v->r, tm + 1, tr, k - v->l->zeroCount);
    }
}


const int N = 131072;

inode zeroes;
inode ones;

inode add(inode v, int pos) {
    int zeroCount = getZeroCount(v, 0, N - 1, 0, pos - 1);
    int kthZero = findKthZero(v, 0, N - 1, zeroCount + 1);
    inode res = setOne(v, 0, N - 1, kthZero);
    res = fillZeroes(res, zeroes, 0, N - 1, pos, kthZero - 1);
    return res;
}

bool compare(const inode &l, const inode &r, int len) {
    if (l->hash == r->hash) {
        return false;
    }
    if (len == 1) {
        return l->hash < r->hash;
    }
    if (l->r->hash == r->r->hash) {
        return compare(l->l, r->l, len >> 1);
    } else {
        return compare(l->r, r->r, len >> 1);
    }
}

long long sum;

const long long mod = 1000000007;

const bool debug = false;

void traverse(inode v, int tl, int tr) {
    if (tl == tr) {
        if (debug) cout << v->hash;
        sum = sum * 2 + v->hash;
        if (sum >= mod) {
            sum -= mod;
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    traverse(v->r, tm + 1, tr);
    traverse(v->l, tl, tm);
}


struct iNumber {
    inode x;
    iNumber(inode z = zeroes) {
        x = z;
    }
    iNumber operator+(const int & r) const {
        return iNumber(add(x, r));
    }
    bool operator<(const iNumber & r) const {
        return compare(r.x, x, N);
    }
    bool operator==(const iNumber & r) const {
        return x->hash == r.x->hash;
    }
    long long value() const {
        sum = 0;
        traverse(x, 0, N - 1);
        if (debug) cout << endl;
        return sum;
    }
};



void initZEROandONE() {
    ONE = inode(new node());
    ONE->hash = 1;
    ONE->pw = 3;
    ONE->zeroCount = 0;

    ZERO = inode(new node());
    ZERO->hash = 0;
    ZERO->pw = 3;
    ZERO->zeroCount = 1;

    zeroes = build(0, N - 1, 0);
    ones = build(0, N - 1, 1);
}

void test() {
    smartPtr<int> z(new int(3));
    smartPtr<int> q = z;

    cout << *q.cnt << endl;


    exit(0);
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    //test();
    initZEROandONE();

//    iNumber zero;
//
//    zero.value();
//
//    iNumber one = zero + 0;
//    iNumber two = one + 0;
//    iNumber three = two + 0;
//    iNumber four = three + 0;
//
//    one.value();
//    two.value();
//    three.value();
//    four.value();

    int n, m;
    scanf("%d%d", &n, &m);

    iNumber infinity(ones);
    iNumber zero(zeroes);

    vector <iNumber> distance(n, infinity);

    vector <pair <int, int> > edges[n];

    for (int i = 0; i < m; ++i) {
        int a, b, len;
        scanf("%d%d%d", &a, &b, &len);
        --a, --b;
        edges[a].push_back(make_pair(b, len));
        edges[b].push_back(make_pair(a, len));
    }

    int s, t;
    scanf("%d%d", &s, &t);
    --s, --t;

    distance[s] = zero;

    priority_queue <pair <iNumber, int> > q;

    q.push(make_pair(distance[s], s));

    vector <int> parent(n, -1);

    while (!q.empty()) {
        auto z = q.top();
        q.pop();
        if (z.first != distance[z.second]) continue;
        int v = z.second;
        for (auto edge : edges[v]) {
            int to = edge.first;
            int len = edge.second;
            iNumber newDistance = distance[v] + len;
            if (distance[to] < newDistance) {
                distance[to] = newDistance;
                q.push(make_pair(distance[to], to));
                parent[to] = v;
            }
        }
    }

    if (distance[t] == infinity) {
        printf("-1\n");
        return 0;
    }

    printf("%lld\n", distance[t].value());

    vector <int> path;

    while (t != -1) {
        path.push_back(t);
        t = parent[t];
    }
    reverse(path.begin(), path.end());

    printf("%d\n", path.size());

    for (int i = 0; i < (int)path.size(); ++i) {
        if (i) printf(" ");
        printf("%d", path[i] + 1);
    }
    printf("\n");

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif
    return 0;
}