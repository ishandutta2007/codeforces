#include <bits/stdc++.h>
using namespace std;
 
int n, b, sum = 0, a[100];
vector<int> cuts;
 
bool comp(int i, int j) {
    return abs(a[i] - a[i+1]) < abs(a[j] - a[j+1]);
}
 
int main() {
    cin >> n >> b;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0)
            sum++;
        else
            sum--;
        if (sum == 0 && i < n - 1)
            cuts.push_back(i);
    }
    sort(cuts.begin(), cuts.end(), comp);
    
    int ret = 0;
    while (ret < cuts.size() && b - abs(a[cuts[ret]]-a[cuts[ret]+1]) >= 0) {
        b -= abs(a[cuts[ret]]-a[cuts[ret]+1]);
        ret++;
    }
    cout << ret << endl;
    
    return 0;
}