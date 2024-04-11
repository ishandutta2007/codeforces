#include <bits/stdc++.h>
using namespace std;

int n;

struct BinaryIndexedTree {
    int BIT[1000001] = {0};

    int getSum(int index) {
        int sum = 0;
        index++;
        while (index > 0) {
            sum += BIT[index];
            index -= index & (-index);
        }
        return sum;
    }
    
    void update(int index, int val) {
        index++;
        while (index <= n) {
            BIT[index] += val;
            index += index & (-index);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int g[1000000], l[1000000];
    pair<int, int> a[1000000], b[1000000];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        b[i] = a[i];
    }
    sort(a, a + n);
    sort(b, b + n, greater<pair<int, int>>());
    
    BinaryIndexedTree b1, b2;
    for (int i=0; i<n; i++) {
        l[a[i].second] = b1.getSum(n-1) - b1.getSum(a[i].second);
        b1.update(a[i].second, 1);
    }
    for (int i=0; i<n; i++) {
        g[b[i].second] = b2.getSum(b[i].second);
        b2.update(b[i].second, 1);
    }
    
    long long ret = 0;
    for (int i=0; i<n; i++)
        ret += (long long) l[i] * g[i];
    cout << ret << "\n";

    return 0;
}