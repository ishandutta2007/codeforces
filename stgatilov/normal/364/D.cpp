//#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int MAXN = 1<<20;
const int SIZE = 1<<20;
bool npr[SIZE];
vector<int> primes;

int n, b;
int64 arr[MAXN];
vector<int64> bases;
vector<int> powers[MAXN];
int powercap[MAXN];

int pcnt[64];

map<vector<int>, int> resh;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
    srand(666);

    npr[0] = npr[1] = true;
    for (int i = 2; i*i < SIZE; i++) if (!npr[i])
        for (int j = i*i; j < SIZE; j += i)
            npr[j] = true;
    for (int i = 0; i<SIZE; i++) if (!npr[i])
        primes.push_back(i);

    scanf("%d", &n);
    for (int i = 0; i<n; i++) scanf("%I64d", &arr[i]);
    for (int i = 0; i<n; i++) {
        int k = ((rand() << 15) ^ rand()) % (i+1);
        swap(arr[i], arr[k]);
    }

    for (int i = 0; i<min(n, 30); i++) {
        int k = i;

        int64 rem = arr[k];
        for (int j = 0; j < primes.size(); j++) {
            int p = primes[j];
            int pwr = 0;
            while (rem % p == 0) {
                rem /= p;
                pwr++;
            }
            if (pwr) bases.push_back(p);
        }
        if (rem > 1) bases.push_back(rem);
    }

    sort(bases.begin(), bases.end());
    bases.resize(unique(bases.begin(), bases.end()) - bases.begin());

    vector<int64> fltr;
    for (int i = 0; i < bases.size(); i++) {
        int64 p = bases[i];
        int cnt = 0;
        for (int j = 0; j<n; j++) {
            cnt += (arr[j] % p) == 0;
            if (!(j & 7) && j > 100 && (0.5 - double(cnt)/j) / sqrt(0.0 + j) > 5.0) break;
        }
        if (2*cnt >= n) fltr.push_back(p);
    }
    bases = fltr;
    b = bases.size();

    for (int i = 0; i<n; i++) {
        int64 rem = arr[i];
        for (int j = 0; j < b; j++) {
            int64 p = bases[j];
            int pwr = 0;
            while (rem % p == 0) {
                rem /= p;
                pwr++;
            }
            powers[i].push_back(pwr);
        }
    }

    for (int i = 0; i<b; i++) {
        memset(pcnt, 0, sizeof(pcnt));
        for (int j = 0; j<n; j++)
            pcnt[powers[j][i]]++;

        int tsum = 0;
        int lim = 0;
        for (; lim<64; lim++) {
            tsum += pcnt[lim];
            if (2*tsum > n)
                break;
        }

        powercap[i] = lim;
    }

    for (int i = 0; i<b; i++) Ef("base = %I64d, max power = %d\n", bases[i], powercap[i]);

    for (int i = 0; i<n; i++) {
        vector<int> elem;
        for (int j = 0; j<b; j++) {
            int q = min(powers[i][j], powercap[j]);
            elem.push_back(q);
        }
        resh[elem]++;
    }

    for (int i = 0; i<b; i++) {
        for (auto it = resh.rbegin(); it != resh.rend(); it++) {
            auto v = it->first;
            v[i]++;
            if (v[i] <= powercap[i]) {
                it->second += resh[v];
            }
            v[i]--;
            if (v[i] > 0) {
                v[i]--;
                if (resh.find(v) == resh.end())
                    resh[v] = 0;
                v[i]++;
            }
        }
    }
    assert(resh[vector<int>(b, 0)] == n);

    int64 ans = 1;
    for (auto it = resh.rbegin(); it != resh.rend(); it++) if (2*it->second >= n) {
        const auto& v = it->first;
        int64 tres = 1;
        for (int i = 0; i<b; i++) {
            for (int j = 0; j<v[i]; j++) tres *= bases[i];
        }
        if (tres > ans) ans = tres;
    }

    printf("%I64d\n", ans);

	return 0;
}