#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 100;

int N;
int rv[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> rv[i];

        while(rv[i] % 2 == 0) {
            rv[i] /= 2;
        }

        while(rv[i] % 3 == 0) {
            rv[i] /= 3;
        }
    }

    bool good = true;

    for (int i = 1; i < N; i++) {
        good &= rv[i] == rv[0];
    }

    cout << (good ? "Yes" : "No") << endl;
}