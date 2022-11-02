#include <bits/stdc++.h>
using namespace std;

constexpr int MaxN = 1000005;

template<class T>
ostream& operator<<(ostream &os, const vector<T> &v) {
    for (T t : v) {
        os << t << " ";
    }
    return os;
}

pair<int, vector<int>> knapsack(vector<int> weights, int target) {
    vector<pair<int, int>> wcount;
    for (int w : weights) {
        if (wcount.empty() || w != wcount.back().first) {
            wcount.emplace_back(w, 1);
        } else {
            wcount.back().second++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> wqueue(weights.begin(), weights.end());
    vector<int> wmerged;
    while (!wqueue.empty()) {
        int w = wqueue.top();
        wqueue.pop();

        int cnt = 1;
        while (!wqueue.empty() && wqueue.top() == w) {
            wqueue.pop();
            cnt++;
        }

        while (cnt > 2) {
            wqueue.push(w*2);
            cnt -= 2;
        }
        while (cnt > 0) {
            wmerged.push_back(w);
            cnt--;
        }
    }

    //cout << "w merged: " << wmerged << endl;

    bitset<MaxN/2> dp;
    dp[0] = true;
    for (int w : wmerged) {
        dp |= dp << w;
    }
    int ans;
    for (ans = target; ans >= 0; ans--) {
        if (dp[ans]) {
            break;
        }
    }

    //cout << "ans " << ans << endl;

    vector<int> soln;
    int cur = ans;
    auto rev_wcount = vector<pair<int, int>>(wcount.rbegin(), wcount.rend());
    for (auto [w, count] : rev_wcount) {
        while (count && cur >= w && dp[cur-w]) {
            count--;
            cur -= w;
            soln.push_back(w);
        }
    }
    reverse(soln.begin(), soln.end());
    assert(cur == 0);

    //cout << "soln: " << soln << endl;
    return {ans, soln};
}

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    int N;
    //cin >> N;
    scanf("%d", &N);
    vector<int> p(N);
    vector<vector<int>> ch(N);
    //vector<vector<int>> e(N);
    for (int i = 1; i < N; i++) {
        //cin >> p[i];
        scanf("%d", &p[i]);
        p[i]--;
        ch[p[i]].push_back(i);
        //e[p[i]].push_back(i);
        //e[i].push_back(p[i]);
    }

    //cout << "input done" << endl;

    int centroid = -1;
    vector<int> sz(N);
    for (int i = N-1; i >= 0; i--) {
        sz[i] = 1;
        bool is_centroid = true;
        for (int j : ch[i]) {
            sz[i] += sz[j];
            if (sz[j] > N/2) {
                is_centroid = false;
            }
        }
        if (N - sz[i] > N/2) {
            is_centroid = false;
        }
        if (is_centroid && centroid == -1) {
            centroid = i;
        }
    }
    assert(centroid != -1);
    //cout << "centroid " << centroid << endl;

    vector<pair<int, int>> weights_and_idxs;
    for (int j : ch[centroid]) {
        weights_and_idxs.emplace_back(sz[j], j);
    }
    if (centroid != 0) {
        weights_and_idxs.emplace_back(N - sz[centroid], p[centroid]);
    }
    sort(weights_and_idxs.begin(), weights_and_idxs.end());
    vector<int> weights;
    vector<int> idxs;
    transform(weights_and_idxs.begin(), weights_and_idxs.end(), back_inserter(weights), [](pair<int, int> p) {
        return p.first;
    });
    transform(weights_and_idxs.begin(), weights_and_idxs.end(), back_inserter(idxs), [](pair<int, int> p) {
        return p.second;
    });
    //cout << "weights: " << weights << endl;
    //cout << "idxs: " << idxs << endl;
    auto [reached, soln] = knapsack(weights, (N-1) / 2);
    vector<int> in, out;
    int in_sz = 0ll;
    {
        int i = 0;
        for (int w : soln) {
            while (i < (int) weights.size() && weights[i] < w) {
                out.push_back(idxs[i]);
                i++;
            }
            assert(i < (int) weights.size() && weights[i] == w);
            in.push_back(idxs[i]);
            in_sz += w;
            i++;
        }
        while (i < (int) weights.size()) {
            out.push_back(idxs[i]);
            i++;
        }
        assert(in_sz == reached);
        //cout << "in: " << in << endl;
        //cout << "out: " << out << endl;
    }

    auto count_ans = [&](auto &self, int i, int from) -> long long {
        long long ans = 0ll;
        long long my_sz = 0ll;
        if (from == p[i]) {
            my_sz = sz[i];
        } else {
            my_sz = N - sz[from];
        }
        ans += my_sz;

        //cout << "counting " << i << " from " << from << ", my size " << my_sz << endl;

        for (int j : ch[i]) {
            if (j != from) {
                ans += self(self, j, i);
            }
        }
        if (i != 0 && p[i] != from) {
            ans += self(self, p[i], i);
        }
        return ans;
    };

    //cout << "in_sz, out_sz " << in_sz+1 << " " << N - in_sz << endl;
    long long ans = ((long long) in_sz + 1) * (N - in_sz);
    for (int i : in) {
        ans += count_ans(count_ans, i, centroid);
    }
    for (int i : out) {
        ans += count_ans(count_ans, i, centroid);
    }
    //cout << ans << endl;
    printf("%lld\n", ans);
}