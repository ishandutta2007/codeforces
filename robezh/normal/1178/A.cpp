#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
int a[N];

int main() {
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<int> res;
    int csum = 0;
    res.push_back(0);
    for(int i = 1; i < n; i++) {
        if(a[0] >= 2 * a[i]) res.push_back(i);
    }
    for(int x : res) csum += a[x]
            ;
    if(sum >= 2 * csum) cout << "0" << endl;
    else {
        cout << res.size() << endl;
        for(int x : res) cout << x + 1  << " ";
    }
}