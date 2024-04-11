#include <cassert>
#include <iostream>
#include <map>
#include <deque>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

int precount[10001];

signed main()
{
    
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> mas(n);
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        precount[a]++;
    }
    
    long long ans = 0;
    for (int i = 0; i < 10001; i++) {
        for (int j = 0; j < 10001; j++) {
            if (__builtin_popcount(i ^ j) == k) {
                if (i == j)
                    ans += ((long long)precount[i] - 1LL) * (long long)precount[i];
                else
                    ans += (long long)precount[i] * (long long)precount[j];
            }
        }
    }
    
    cout << ans / 2;
    
    
    return 0;
}