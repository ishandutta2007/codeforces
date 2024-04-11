#include<bits/stdc++.h>
#define int long long
#define p pair<int, int>
//#define endl '\n'

using namespace std;

struct DO{
    vector<int> do_arr;
    int len;

    DO(vector<p> &a) {
        int q1 = 1;
        while (q1 < a.size()) {
            q1 *= 2;
        }
        len = q1;
        for (int q = 0; q < q1 * 2; q++) {
            do_arr.push_back(0);
        }
    }

    void change(int q, int x){
        do_arr[q+len] = x;
        q = (q+len)/2;
        while (q > 0){
            do_arr[q] = do_arr[2*q]+do_arr[2*q+1];
            q /= 2;
        }
    }

    int ans(int l, int r, int l1, int r1, int q){
        if (r <= l1 || r1 <= l){
            return 0;
        }
        if (l1 <= l && r <= r1){
            return do_arr[q];
        }
        int m = (l+r)/2;
        return ans(l, m, l1, r1, 2*q)+ans(m, r, l1, r1, 2*q+1);
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for (int q = 0; q < n; q++){
        cin >> a[q];
    }
    vector<p> d, d1;
    vector<pair<p, p>> s;
    unordered_map<int, int> was;
    for (int q = 0; q < n; q++){
        if (was.find(a[q]) != was.end()){
            int w = was[a[q]];
            s.push_back({{w, q}, {-1, -1}});
            d.push_back({min(w, n-q-1)+q-w+1, s.size()-1});
            d1.push_back({n-min(w, n-q-1), s.size()-1});
            was[a[q]] = q;
        }else{
            was[a[q]] = q;
        }
    }
    sort(d.begin(), d.end());
    sort(d1.begin(), d1.end());
    for (int q = 0; q < d.size(); q++){
        s[d[q].second].second.first = q;
        s[d1[q].second].second.second = q;
    }
    int OPKP = 0;
    sort(s.begin(), s.end(), [](pair<p, p> x, pair<p, p> y){ return x.first.second-x.first.first < y.first.second-y.first.first;});
    DO do_arr = *(new DO(d)), do_arr1 = *(new DO(d1));
    int q1 = 0, ans = 0, q2 = 0, q3 = 0;
    for (int q = 1; q < n+1; q++){
        while (q1 < s.size() && s[q1].first.second-s[q1].first.first == q-1){
            do_arr.change(s[q1].second.first, 1);
            do_arr1.change(s[q1].second.second, 1);
            q1++;
        }
        while (q2 < d.size() && d[q2].first < q){
            q2++;
        }
        while (q3 < d1.size() && d1[q3].first < q){
            q3++;
        }
        ans += do_arr.ans(0, do_arr.len, q2, n, 1)-do_arr1.ans(0, do_arr.len, 0, q3, 1);
        OPKP += q*(n-q+1)-ans;
    }
    OPKP += OPKP - n;
    int g = n * n;
    cout << fixed;
    cout << 1.0 * OPKP / g << '\n';
    return 0;
}