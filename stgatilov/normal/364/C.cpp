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

const int SIZE = 5<<10;
bool npr[SIZE];
vector<int> primes;

int n, bound;
int k;

vector<int> all;
bool Solve(int u, int curr) {
    if (u == k) {
        all.push_back(curr);
        return (all.size() >= n);
    }
    for (int i = curr; i <= bound; i *= primes[u])
        if (Solve(u+1, i))
            return true;
    return false;
}

bool Validate(const vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < primes.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < arr.size(); j++)
            cnt += (arr[j] % primes[i]) == 0;
        if (cnt == 0) continue;
        if (2*cnt < n) {
            Ef("Number of %d is %d/%d\n", primes[i], cnt, n);
            return false;
        }
    }
    for (int j = 0; j < arr.size(); j++)
        if (arr[j] > 2*n*n) {
            Ef("Number is too large: %d/%d\n", arr[j], 2*n*n);
            return false;
        }
    return true;
}

bool DoAll(int number) {
    n = number;
    bound = 2*n*n;

//    for (k = primes.size()-1; k >= 0 ; k--) {
    for (k = 2; k < primes.size(); k++) {
        all.clear();
        Solve(0, 1);
        if (all.size() == n) break;
    }

    if (!Validate(all))
        return false;
    return true;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

    npr[0] = npr[1] = true;
    for (int i = 2; i*i < SIZE; i++) if (!npr[i])
        for (int j = i*i; j < SIZE; j += i)
            npr[j] = true;
    for (int i = 0; i<SIZE; i++) if (!npr[i])
        primes.push_back(i);

/*    for (int num = 10; num <= 5000; num++) {
        Eo(num);
        bool ok = DoAll(num);
        Eo(ok);
        if (!ok) printf("Error: %d\n", num);
    }*/

    scanf("%d", &n);
    DoAll(n);
    for (int i = 0; i<n; i++) printf("%d ", all[i]);

	return 0;
}