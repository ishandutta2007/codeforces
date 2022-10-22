#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> flp(int x) {
    vector<int> ans;
    if (x < 2) {
        return ans;
    }
    for (int i = 2; i < 100000; ++i) {
        if (x % i == 0) {
            ans.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ind1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            ind1.push_back(i);
        }
        sum += a[i];
    }

    vector<int> lp = flp(sum);
    if (lp.empty()) {
        cout << "-1\n";
        return 0;
    }
    ll mans = 1111111111111LL;
    for (int q = 0; q < lp.size(); ++q) {
        //cout << lp[q] << " ";
        ll ans = 0;
        for (int i = 0; i < sum / lp[q]; ++i) {
            int ci = lp[q] * i + lp[q] / 2;
            for (int j = lp[q] * i; j < lp[q] * i + lp[q]; ++j) {
                ans += abs(ind1[j] - ind1[ci]);
            }
        }
        //cout << ans << "; ";
        mans = min(mans, ans);
    }

    cout << mans << '\n';

    return 0;
}