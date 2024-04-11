#include <bits/stdc++.h>
using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    vector<pair<int, double>> s;
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        s.emplace_back(1, a);
        while (true) {
            auto p = s.back();
            if (s.size() == 1 || s[s.size()-2].second < p.second)
                break;
            s.pop_back();
            auto q = s.back();
            s.pop_back();
            s.emplace_back(p.first + q.first, (p.first * p.second + q.first * q.second) / (p.first + q.first));
        }
    }

    for (auto p : s)
        for (int i=0; i<p.first; i++)
            printf("%.10f\n", p.second);

    return 0;
}