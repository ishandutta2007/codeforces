#include <bits/stdc++.h>

using namespace std;
constexpr int DIFFMAX = 3000000;

vector<pair<int, int>> diffAt[DIFFMAX];

int main() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    vector<int> sid(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    iota(begin(sid), end(sid), 0);
    sort(begin(sid), end(sid), [&] (int i, int j) {
        if (arr[i] != arr[j]) return arr[i] < arr[j];
        else return i < j;
    });
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int ai = arr[sid[i]], aj = arr[sid[j]];
//            printf("checking %d %d at %d\n", sid[i], sid[j], aj - ai);
            bool canMemo = true;
            for (auto [sax, say] : diffAt[aj - ai]) {
                if (say != sid[i] && say != sid[j] && sax != sid[i]) {
                    int x = i, z = j;
                    int y = sax, w = say;
                    x = sid[x]; z = sid[z];
                    printf("YES\n");
                    printf("%d %d %d %d\n", y + 1, z + 1, x + 1, w + 1);
                    return 0;
                } else if (sax == sid[i]) canMemo = false;
            }
            if (canMemo) diffAt[aj - ai].emplace_back(sid[i], sid[j]);
        }
    }
    printf("NO\n");
}