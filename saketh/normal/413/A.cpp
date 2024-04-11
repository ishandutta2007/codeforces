#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, M, dmin, dmax;
    cin >> N >> M >> dmin >> dmax;

    int amin = 0x7fffffff, amax = 0;

    for (int i = 0; i < M; i++) {
        int V;
        cin >> V;

        amin = min(amin, V);
        amax = max(amax, V);
    }

    if (amin < dmin || amax > dmax) {
        cout << "Incorrect\n";
    }
    else {
        // min and max are distinct
        int need = int(amin != dmin) + int(amax != dmax);
        if(M + need > N) cout << "Incorrect\n";
        else cout << "Correct\n";
    }
}