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

bool mutant_landfill(vector<pair<int, pair<int, int>>> &bohr, vector<long long> &b, vector<bool> &used, int bit, int &cnt, int v, long long &bitmask) {
    if (cnt >= b.size()) return true;

    if (bohr[v].second.first == -1 && !((bitmask >> bit) & 1)) {
        for (; cnt < b.size(); cnt++) {
            if (!used[cnt] && ((b[cnt] >> bit) & 1)) {
                used[cnt] = true;
                bohr[v].second.first = bohr.size();
                bohr.emplace_back(cnt, make_pair(-1, -1));
                bitmask ^= b[cnt];
                break;
            }
        }
    }
    else if (bohr[v].second.first != -1) mutant_landfill(bohr, b, used, bit, cnt, bohr[v].second.first, bitmask);

    bitmask ^= b[bohr[v].first];

    if (bohr[v].second.second == -1 && !((bitmask >> bit) & 1)) {
        for (; cnt < b.size(); cnt++) {
            if (!used[cnt] && ((b[cnt] >> bit) & 1)) {
                used[cnt] = true;
                bohr[v].second.second = bohr.size();
                bohr.emplace_back(cnt, make_pair(-1, -1));
                bitmask ^= b[cnt];
                break;
            }
        }
    }
    else if (bohr[v].second.second != -1) mutant_landfill(bohr, b, used, bit, cnt, bohr[v].second.second, bitmask);

    if (v == 0) {
        for (; cnt < b.size(); cnt++) {
            if (!used[cnt] && ((b[cnt] >> bit) & 1)) {
                return false;
            }
        }
        return true;
    }
}

//long long bmt = 0;

void traverse(vector<pair<int, pair<int, int>>> &bohr, vector<long long> &b, int v) {
    if (bohr[v].second.first != -1) traverse(bohr, b, bohr[v].second.first);
    //bmt ^= b[bohr[v].first];
    //cout << bmt << ' ';
    cout << b[bohr[v].first] << ' ';
    if (bohr[v].second.second != -1) traverse(bohr, b, bohr[v].second.second);
}

void solve(istream &cin = std::cin, ostream &cout = std::cout) {
    int n;
    cin >> n;

    vector<long long> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> cnt_bits(60);
    for (int i = 0; i < n; i++) {
        for (int bit = 0; bit < 60; bit++) {
            cnt_bits[bit] += (b[i] >> bit) & 1;
        }
    }

    vector<bool> used(n);

    vector<pair<int, pair<int, int>>> bohr;

    for (int start = 59; start >= 0; start--) {
        if (cnt_bits[start] > 0) {
            if (cnt_bits[start] > 1) {
                cout << "No" << endl;
                return;
            }
            else {
                for (int i = 0; i < n; i++) {
                    if ((b[i] >> start) & 1) {
                        bohr.emplace_back(i, make_pair(-1, -1));
                        used[i] = true;
                    }
                }

                int cnt = 0;
                long long bitmask = 0;
                for (int bit = start - 1; bit >= 0; bit--) {
                    if (!mutant_landfill(bohr, b, used, bit, cnt, 0, bitmask)) {
                        cout << "No" << endl;
                        return;
                    }
                    cnt = 0;
                    bitmask = 0;
                }

                cout << "Yes" << endl;
                traverse(bohr, b, 0);
                cout << endl;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}