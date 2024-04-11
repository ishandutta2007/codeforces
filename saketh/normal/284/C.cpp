#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N = 1, Q;
    ll sum = 0;

    vector<int> val(1, 0);
    vector<int> add(1, 0);


    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int T;
        cin >> T;

        if (T == 1) {
            ll X, K;
            cin >> K >> X;

            sum += X * K;
            add[K-1] += X;
        }
        else if (T == 2) {
            int V;
            cin >> V;

            sum += V;
            val.push_back(V);
            add.push_back(0);
            N++;
        }
        else {
            N--;
            sum -= val[N];
            val.pop_back();
            sum -= add[N];
            add[N-1] += add[N];
            add.pop_back();
        }

        cout << sum / double(N) << "\n";
    }
}