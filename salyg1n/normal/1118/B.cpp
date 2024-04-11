#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

typedef long long ll;

using namespace std;

int p_even[(int)2e5 + 10];
int p_odd[(int)2e5 + 10];
int a[(int)2e5 + 10];

int main() {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
                cin >> a[i];
        for (int i = 2; i <= n; i += 2)
                p_even[i] = p_even[i - 2] + a[i];
        p_odd[1] = a[1];
        for (int i = 3; i <= n; i += 2)
                p_odd[i] = p_odd[i - 2] + a[i];
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
                int even = p_even[i - 1] + p_even[i - 2] + p_odd[n-1] + p_odd[n] - p_odd[i-1] - p_odd[i];
                int odd = p_odd[i - 1] + p_odd[i - 2] + p_even[n - 1] + p_even[n] - p_even[i - 1] - p_even[i];
                if (even == odd)
                        ans++;
        }
        cout << ans;
        return 0;
}