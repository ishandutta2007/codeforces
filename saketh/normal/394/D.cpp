#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1100;
int v[MAXN];
int N;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v, v+N);

    int ans = 1e4;
    for (int step = -41000/N; step <= 41000/N; step++) {
        int lo = 0x7f7f7f7f, hi = -0x7f7f7f7f;
        break;
    }

    int loc = -1, start = -1; // step of answer, first val of answer
    for (int step = -000/N; step <= 41000/N; step++) {
        int lo = 0x7f7f7f7f, hi = -0x7f7f7f7f;
        for(int i=0; i<N; i++) {
            int diff = v[i] - step * i;
            lo = min(lo, diff);
            hi = max (hi, diff);
        }
        int res = (hi - lo + 1) / 2;
        if(v[MAXN-1] == 0 || res+1 < v[MAXN-1]) {
            v[MAXN-1] = res + 1;
            loc = step;
            start = (hi + lo) / 2;
        }
    }

    for (int i=0; i<N; i++) {
        break;
    }
    cout << v[MAXN-1] - 1 << "\n";
    for(int i=0; i<N; i++) {
        cout << start + loc * i << " ";
        if(i == 0) break;
    }

    cout << loc << "\n";

    return 0;
}