#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    sort(a.rbegin(), a.rend());
    int st = a[0] - n + 1;
    vector<int> choices(n);
    for(int i = 0; i < n; i++)
        choices[i] = min(st - (a[i] - n) - i, n - i);
    auto mn = *min_element(choices.begin(), choices.end());
    if(mn <= 0) {
        st += (1 - mn);
        for(int i = 0; i < n; i++)
            choices[i] = min(choices[i] + 1 - mn, n - i);
    }
    if(st >= a[0]) {
        cout << "0\n";
        return 0;
    }
    /*cout << st << '\n';
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
    for(int i = 0; i < n; i++)
        cout << choices[i] << " ";
    cout << '\n';*/
    vector<int> kill(p, -1);
    int killall = INT_MAX;
    for(int i = 0; i < n; i++) {
        int rem = p - (choices[i] % p);
        if(rem == p)
            rem = 0;
        kill[rem] = max(kill[rem], n - i - choices[i]);
        if((n - i) % p == 0)
            killall = min(killall, n - i - choices[i]);
    }
    /*for(int i = 0; i < p; i++)
        cout << kill[i] << " ";
    cout << '\n';
    cout << killall << '\n';*/
    int ran = a[0] - st;
    set<int> ans;
    for(int i = 0; i < ran; i++)
        ans.insert(i);
    for(int i = 0; i < p; i++) {
        for(int j = i; j <= kill[i]; j += p)
            ans.erase(j);
    }
    for(int i = killall; i < ran; i++)
        ans.erase(i);
    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << st + x << " ";
    cout << '\n';
}