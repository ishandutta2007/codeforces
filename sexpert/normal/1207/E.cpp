#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int LMAO = 128;
vector<int> q1, q2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < 100; i++) {
        q1.push_back(i);
        q2.push_back(LMAO * i);
    }
    cout << "? ";
    for(auto q : q1)
        cout << q << " ";
    cout << '\n';
    cout.flush();
    int hi;
    cin >> hi;
    hi = (hi / LMAO) * LMAO;
    cout << "? ";
    for(auto q : q2)
        cout << q + LMAO << " ";
    cout << '\n';
    cout.flush();
    int lo;
    cin >> lo;
    lo %= LMAO;
    cout << "! " << lo + hi << '\n';
}