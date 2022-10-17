#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, K;
int val[200000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K;

    int A = -1, B = 0x7fffffff;
    int S = 0;

    for (int i = 0; i < N; i++) {
        cin >> val[i];
        if (i >= K) S -= val[i-K];
        S += val[i];
        if (i >= K-1 && S < B) {
            B = S;
            A = i - K + 2;
        }
    }

    cout << A << endl;
}