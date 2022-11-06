#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<long long> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    vector<vector<int>> siz(31, vector<int>(1, 0));
    vector<vector<int>> zlink(31, vector<int>(1, -1));
    vector<vector<int>> olink(31, vector<int>(1, -1));
    vector<long long> num(1);

    for (int i = 0; i < N; i++) {
        int pt = 0;
        for (int j = 30; j > 0; j--) {
            siz[j][pt]++;
            bool is_one = (P[i] >> (j - 1)) & 1;
            if ((is_one ? olink[j][pt] : zlink[j][pt]) >= 0) {
                pt = (is_one ? olink[j][pt] : zlink[j][pt]);
            }
            else {
                (is_one ? olink[j][pt] : zlink[j][pt]) = siz[j - 1].size();
                pt = siz[j - 1].size();
                siz[j - 1].push_back(0);
                zlink[j - 1].push_back(-1);
                olink[j - 1].push_back(-1);
                if (j == 1) num.push_back(P[i]);
            }
        }
        siz[0][pt]++;
    }

    for (int i = 0; i < N; i++) {
        long long pt = 0;
        for (int j = 30; j > 0; j--) {
            siz[j][pt]--;
            bool is_one = (A[i] >> (j - 1)) & 1;
            if (is_one) {
                if (olink[j][pt] >= 0 && siz[j - 1][olink[j][pt]] > 0) pt = olink[j][pt];
                else pt = zlink[j][pt];
            }
            else {
                if (zlink[j][pt] >= 0 && siz[j - 1][zlink[j][pt]] > 0) pt = zlink[j][pt];
                else pt = olink[j][pt];
            }
        }
        siz[0][pt]--;
        cout << (A[i] ^ num[pt]) << ' ';
    }

    cout << endl;

    return 0;
}