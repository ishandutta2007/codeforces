#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define pa pair
#define tu tuple

typedef uint32_t uint;
typedef int64_t ll;

typedef ve<int> vi;
typedef ve<vi> v2i;
typedef pa<int, int> pii;

void
answer(int x)
{
    cout << "! " << x << endl;
}

int
get(int x)
{
    static map<int, int> cache;
    auto it = cache.find(x);
    if (it == cache.end()) {
        cout << "? " << x << endl;
        int res;
        cin >> res;
        it = cache.insert({x, res}).first;
    }
    return it->second;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n == 1) {
        answer(1);
    } else {
        int l = 1, r = n;
        while (r - l + 1 >= 8) {
            int m = (l + r) / 2;
            int a_m = get(m), a_m1 = get(m + 1);
            if (a_m < a_m1) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        int i = l;
        while (i < r && get(i) > get(i + 1)) ++i;
        answer(i);
    }
    return 0;
}