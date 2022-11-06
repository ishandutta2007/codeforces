#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& i : p) {
        cin >> i;
        i--;
    }
    vector<int> s(n);
    for (auto& i : s) {
        cin >> i;
        i--;
    }
    vector<int> poss(n);
    for (int i = 0; i < n; i++) poss[s[i]] = i;
    for (auto& i : p) i = poss[i];
    //for (auto i : p) cout << i + 1 << " ";
    //cout << endl;
    vector<pair<int, int>> out;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int ind = 0;
        while (p[ind] != i) ind++;
        int lst = ind + 1;
        while (ind != i) {
       //     cout << lst << endl;
        //    cout << ind << endl;
          //  for (int j = lst; j <= i; j++) cout << p[j] + 1 << " ";
           // cout << endl;
            while (p[lst] > ind) lst++;
            ans += abs(lst - ind);
            swap(p[ind], p[lst]);
            out.emplace_back(ind + 1, lst + 1);
            ind = lst++;
        }
        //cout << i + 1 << endl;
    }
    cout << ans << '\n' << out.size() << '\n';
    for (auto i : out) cout << i.first << " " << i.second << '\n';
    return 0;
}