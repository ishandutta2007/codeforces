#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <climits>

using namespace std;

typedef long long ll;

#define maxn 300500

int n, w;
int a[maxn], b[maxn];
ll sum1[2 * maxn];
ll sum2[2 * maxn];
int add2[2 * maxn];
int cnt[maxn];

vector< int > t2;
vector< pair< int, int > > t1;

class C1
{
public:
    bool operator()(int x, int y)
    {
        return ((b[x] - a[x]) > (b[y] - a[y]) || ((b[x] - a[x]) == (b[y] - a[y]) && x < y));
    }
};

class C2
{
public:
    bool operator()(int x, int y)
    {
        return ((a[x] < a[y]) || (a[x] == a[y] && x < y));
    }
};

bool
cmp_fst(int x, int y)
{
    return (b[x] < b[y] || (b[x] == b[y] && a[x] < a[y]) ||
            (b[x] == b[y] && a[x] == a[y] && x < y));
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> w;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        if (b[i] - a[i] >= a[i]) {
            t1.push_back(make_pair(a[i], i));
            t1.push_back(make_pair(b[i] - a[i], i));
        } else {
            t2.push_back(i);
        }
    }
    sort(t1.begin(), t1.end());
    sum1[0] = 0LL;
    int pos1 = 0;
    for (vector< pair< int, int > >::iterator it = t1.begin(); it != t1.end(); ++it, ++pos1) {
        sum1[pos1 + 1] = sum1[pos1] + it->first;
    }
    sort(t2.begin(), t2.end(), cmp_fst);
    set< int, C1 > st1;
    set< int, C2 > st2(t2.begin(), t2.end());
    int pos2 = 0;
    sum2[0] = 0LL;
    for (vector< int >::iterator add = t2.begin(); add != t2.end(); ++add, ++pos2) {
        int cur_v = *add;
        sum2[pos2 * 2 + 2] = sum2[pos2 * 2] + b[cur_v];
        sum2[pos2 * 2 + 1] = sum2[pos2 * 2] + a[*(st2.begin())];
        add2[pos2 * 2 + 1] = *(st2.begin());
        st2.erase(cur_v);
        st1.insert(cur_v);
        int min_v = *(st1.begin());
        if (sum2[pos2 * 2 + 1] > sum2[pos2 * 2 + 2] - b[min_v] + a[min_v]) {
            sum2[pos2 * 2 + 1] = sum2[pos2 * 2 + 2] - (b[min_v] - a[min_v]);
            add2[pos2 * 2 + 1] = -min_v - 1;
        }
    }
    ll res = LLONG_MAX;
    int ind = -1;
    for (int i = 0; i <= 2 * pos2; ++i) {
        int df = w - i;
        if (df >= 0 && df <= pos1 && res > sum1[df] + sum2[i]) {
            res = sum1[df] + sum2[i];
            ind = i;
        }
    }
    int df = w - ind;
    //cerr << "df = " << df << endl;
    //cerr << "ind = " << ind << endl;
    for (int i = 0; i < df; ++i) {
        //cerr << "t1 " << t1[i].second << endl;
        cnt[t1[i].second]++;
    }
    for (int i = 0; (i * 2) < (ind & -2); ++i) {
        //cerr << "add i = " << t2[i] << endl;
        cnt[t2[i]] += 2;
    }
    if (ind % 2 == 1) {
        if (add2[ind] >= 0) { // adding from ind - 1
            //cerr << "add " << endl;
            ++cnt[add2[ind]];
        } else { // deleting from ind + 1
            //cerr << "delete " << -add2[ind] - 1 << endl;
            //cerr << "add " << t2[(ind) / 2] << endl;
            cnt[t2[ind / 2]] += 2;
            --cnt[-add2[ind] - 1];
        }
    }
    cout << res << '\n';
    for (int i = 0; i < n; ++i) {
        cout << cnt[i];
    }
    cout << '\n';
    return 0;
}