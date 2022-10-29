#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector< int > w(n, 0), h(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> h[i];
    }
    int sum_w = std::accumulate(w.begin(), w.end(), 0);
    int max_id = 0, max_id_2 = -1;
    for (int i = 1; i < n; ++i) {
        if (max_id_2 == -1 || h[max_id_2] < h[i]) {
            max_id_2 = i;
        }
        if (h[max_id] < h[max_id_2]) {
            swap(max_id, max_id_2);
        }
    }
    for (int i = 0; i < n; ++i) {
        int cur_sum = sum_w - w[i];
        int cur_max = (i == max_id) ? h[max_id_2] : h[max_id];
        cout << cur_max * cur_sum << ' ';
    }
    cout << '\n';
    return 0;
}