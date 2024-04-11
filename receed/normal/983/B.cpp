#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;
 
using namespace std;

const int N = 5001;
ll a[N][N];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> a[0][i];
    for (int i = 0; i < n - 1; i++)
    	for (int j = 0; j < n - i - 1; j++)
    		a[i + 1][j] = a[i][j] ^ a[i][j + 1];
    for (int i = 0; i < n - 1; i++)
    	for (int j = 0; j < n - i - 1; j++)
    		a[i + 1][j] = max(a[i + 1][j], max(a[i][j], a[i][j + 1]));
    int q, l, r;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	cin >> l >> r;
    	cout << a[r - l][l - 1] << '\n';
    }
}