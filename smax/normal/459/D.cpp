#include <bits/stdc++.h>
using namespace std;
 
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
    while (index <= 1000000) {
        BIT[index] += val;
        index += index & (-index);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a[1000000], l[1000000], r[1000000];
    unordered_map<int, int> freql, freqr;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        l[i] = ++freql[a[i]];
    }
    for (int i=n-1; i>=0; i--)
        r[i] = ++freqr[a[i]];
    
    long long ret = 0;
    for (int i=n-1; i>=0; i--) {
        ret += getSum(l[i]-1);
        update(r[i], 1);
    }
    
    cout << ret << "\n";
 
    return 0;
}