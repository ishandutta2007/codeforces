#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n,k;
int tp[N];

int check(int b) {
    int e = 0, s = 0;
    for(int j = 0; j < n; j++) {
        if(j % k == b) continue;
        if(tp[j] == 1) e ++;
        else s++;
    }
    return abs(e - s);
}

int main() {
    int res = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> tp[i];
    for(int i = 0; i < k; i++) res = max(res, check(i));
    cout << res << endl;
}