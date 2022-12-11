#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

#define y1 yy1
#define ff first
#define ss second

typedef int ll;
typedef long double ld;

using namespace std;

const ll N = 1e3 + 34;
const ld eps = 1e-10;
const ll C = 3;

int n1, n2, n3, t1, t2, t3, p1, p2, p3, k, st;
set <pair<int, int> > s1, s2, s3;
set <pair<int, int> > :: iterator it;
pair <int, int> m1, m2, m3;

int main()
{
    //freopen("a.in", "r", stdin);

    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    for (int i = 0; i < n1; i++) s1.insert(make_pair(0, i));
    for (int i = 0; i < n2; i++) s2.insert(make_pair(0, i));
    for (int i = 0; i < n3; i++) s3.insert(make_pair(0, i));

    while (k--) {
        m1 = *(s1.begin());
        s1.erase(m1);
        m2 = *(s2.begin());
        s2.erase(m2);
        m3 = *(s3.begin());
        s3.erase(m3);
        st = max(m1.ff, max(m2.ff - t1, m3.ff - t1 - t2));
        s1.insert(make_pair(st + t1, m1.ss));
        s2.insert(make_pair(st + t1 + t2, m2.ss));
        s3.insert(make_pair(st + t1 + t2 + t3, m3.ss));
    }

    it = s3.end();
    it--;

    cout << (*it).ff << "\n";

    return 0;
}