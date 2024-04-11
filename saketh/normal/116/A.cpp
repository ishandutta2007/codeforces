#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N;
    cin >> N;

    int A = 0, C = 0;

    for (int i = 0; i < N; i++) {
        int on, off;
        cin >> off >> on;

        C -= off;
        C += on;

        A = max(A, C);
    }

    cout << A << endl;
}