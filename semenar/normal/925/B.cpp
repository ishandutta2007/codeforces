#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <random>
#include <map>
#include <iomanip>
#include <sstream>

using namespace std;

int inf = (int)1e9 + 7;

struct fraction {
    int p;
    int q;

    friend bool operator<(fraction a, fraction b);
};

bool operator<(fraction a, fraction b) {
    return (long long)a.p * b.q < (long long)a.q * b.p;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout) {
    int n;
    cin >> n;

    long long S_1, S_2;
    cin >> S_1 >> S_2;

    vector<pair<long long, int>> stress(n);
    for (int i = 0; i < n; i++) {
        cin >> stress[i].first;
        stress[i].second = i + 1;
    }

    sort(stress.begin(), stress.end());
    reverse(stress.begin(), stress.end());

    for (int i = 0; i < n; i++) {
        if (stress[i].first * (i + 1) >= S_1) {
            for (int j = i + 1; j < n; j++) {
                if (stress[j].first * (j - i) >= S_2) {
                    cout << "Yes" << endl;
                    cout << i + 1 << ' ';
                    cout << j - i << endl;
                    for (int k = 0; k <= i; k++) cout <<  stress[k].second << ' ';
                    cout << endl;
                    for (int k = i + 1; k <= j; k++) cout << stress[k].second << ' ';
                    cout << endl;
                    return;
                }
            }
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (stress[i].first * (i + 1) >= S_2) {
            for (int j = i + 1; j < n; j++) {
                if (stress[j].first * (j - i) >= S_1) {
                    cout << "Yes" << endl;
                    cout << j - i << ' ';
                    cout << i + 1 << endl;
                    for (int k = i + 1; k <= j; k++) cout << stress[k].second << ' ';
                    cout << endl;
                    for (int k = 0; k <= i; k++) cout << stress[k].second << ' ';
                    cout << endl;
                    return;
                }
            }
            break;
        }
    }

    cout << "No" << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}