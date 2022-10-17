#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
int votes[105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> votes[i];
    }

    int low = 1e9;

    for (int ans = 1; ans <= 1001; ans++) {
        int steal = max(0, ans - votes[0]);
        int force = 0;

        for (int i = 1; i < N; i++) {
            force += max(0, votes[i] - ans + 1);
        }

        low = min(low, max(steal, force));
    }

    cout << low << endl;
}