#include <bits/stdc++.h>
using namespace std;
vector <pair <int, string> > e;
string ch;
int ti, to, n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch >> ti >> to;
        e.push_back(make_pair(ti, "+" + ch));
        e.push_back(make_pair(to, "-" + ch));
    }
    sort(e.begin(), e.end());
    int m = 0, f = 0, ans = 0;
    for (int i = 0; i < e.size(); i++) {
        if (e[i].second[0] == '+')
            if (e[i].second[1] == 'M')
                m++;
            else
                f++;
        else
            if (e[i].second[1] == 'M')
                m--;
            else
                f--;
        ans = max(ans, min(m, f));
    }
    printf("%d", ans * 2);
}