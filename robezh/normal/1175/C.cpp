#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)2e5 + 50;
const int INF = (int)1e9 + 50;

int n, k;
int a[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        int mnlen = INF, mni = -1;
        for(int i = 0; i + k < n; i++) {
            if(a[i+k] - a[i] < mnlen) {
                mnlen = a[i+k] - a[i];
                mni = (a[i+k] + a[i]) / 2;
            }
        }
        cout << mni << "\n";
    }

}