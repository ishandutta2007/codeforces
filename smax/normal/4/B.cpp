#include <bits/stdc++.h>
using namespace std;

int maxTime[30], ret[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int d, sumTime;
    cin >> d >> sumTime;
    for (int i=0; i<d; i++) {
        cin >> ret[i] >> maxTime[i];
        sumTime -= ret[i];
    }

    if (sumTime < 0)
        cout << "NO\n";
    else {
        for (int i=0; i<d; i++) {
            int diff = min(maxTime[i] - ret[i], sumTime);
            ret[i] += diff;
            sumTime -= diff;
        }
        if (sumTime > 0)
            cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i=0; i<d; i++)
                cout << ret[i] << " ";
        }
    }

    return 0;
}