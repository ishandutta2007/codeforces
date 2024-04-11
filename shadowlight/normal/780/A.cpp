/*
ZDRAVSTVUYTE
ESLI VI HOTITE MENYA VZLOMAT'
YA VAM SRAZU SKAZHU
TUT BAGOV NETU
UDACHNOGO VZLOMA
SPASIBO ZA VNIMANIE
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> used(n + 1, 0);
    int now = 0;
    int maxk = 0;
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        if (used[x]) {
            now--;
        } else {
            used[x] = 1;
            now++;
        }
        maxk = max(maxk, now);
    }
    cout << maxk;
}