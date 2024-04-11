#include <bits/stdc++.h>
using namespace std;

string s;
int n, k;

bool check(int m) {
    int cta = 0, ctb = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a')
            cta++;
        else
            ctb++;
        if(i >= m - 1) {
            if(min(cta, ctb) <= k)
                return true;
            if(s[i - m + 1] == 'a')
                cta--;
            else
                ctb--;
        }
    }
    return false;
}

int bs() {
    int lo = 1, hi = n;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(check(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    return lo;
}

int main() {
    cin >> n >> k >> s;
    cout << bs() << endl;
}