#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 100500;

vector< pair< int, int > > ans;
vector< int > primes;
bool isPrime[MAXN];
int n;
bool inMatching[MAXN];

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        isPrime[i] = true;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    primes.clear();
    primes.reserve(100);
    for (int i = n; i > 2; --i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        inMatching[i] = false;
    }
    int tmp[] = {0, 0};
    int cnt = 0;
    for (vector< int >::iterator it = primes.begin(); it != primes.end(); ++it) {
        int p = *it;
        int upper_limit = (n / p);
        if (upper_limit == 1) {
            continue;
        }
        for (int j = upper_limit, val = p * j; j >= 1; --j, val -= p) {
            if (!inMatching[val]) {
                inMatching[val] = true;
                tmp[cnt++] = val;
            }
            if (cnt == 2) {
                ans.push_back(make_pair(tmp[0], tmp[1]));
                cnt = 0;
            }
        }
        if (cnt == 1) { // p lies in tmp, and 2 * p used in previous matching
            ans.back().second = p;
            inMatching[p] = true;
            inMatching[2 * p] = false;
        }
        cnt = 0;
    }
    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 0 && !inMatching[i]) {
            tmp[cnt++] = i;
        }
        if (cnt == 2) {
            ans.push_back(make_pair(tmp[0], tmp[1]));
            cnt = 0;
        }
    }
    cout << ans.size() << '\n';
    for (vector< pair< int, int > >::iterator it = ans.begin(); it != ans.end(); ++it) {
        cout << it->first << " " << it->second << '\n';
    }
    return 0;
}