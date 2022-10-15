#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
//
using namespace std;

#define eps 1e-13
#define ll long long

ll cross_gpairs(vector<double>& left, vector<double>& right, bool eql)
{
    ll ans = 0;
    double change = eql ? eps : -eps;
    int leftptr = 0;
    for (int i = 0; i < right.size(); i++) {
        while (leftptr < left.size() && left[leftptr] < right[i] + change) leftptr++;
        ans += (ll)leftptr;
    }
    return ans;
}

ll gpairs(vector<double>& seq, bool eql)
{
    ll ans = 0;
    double change = eql ? eps : -eps;
    if (seq.size() <= 4) {
        for (int i = 0; i < seq.size(); i++) {
            for (int j = i + 1; j < seq.size(); j++) {
                if (seq[i] < seq[j] + change) ans++;
            }
        }
        sort(seq.begin(), seq.end());
        return ans;
    }
    vector<double> left;
    vector<double> right;
    for (int i = 0; i < seq.size() / 2; i++) {
        left.push_back(seq[i]);
    }
    for (int i = seq.size() / 2; i < seq.size(); i++) {
        right.push_back(seq[i]);
    }
    ans += gpairs(left, eql) + gpairs(right, eql);
    ans += cross_gpairs(left, right, eql);
    seq.clear(); int curleft = 0, curright = 0;
    while (curleft < left.size() || curright < right.size()) {
        if (curleft < left.size() && (curright == right.size() || left[curleft] < right[curright])) {
            seq.push_back(left[curleft]); curleft++;
        } else {
            seq.push_back(right[curright]); curright++;
        }
    }
    return ans;
}

ll bpairs(vector<double>& seq, bool eql)
{
    ll base = (seq.size() * (seq.size() - 1)) / 2;
    return base - gpairs(seq, !eql);
}

int n, w;
int x[100005]; int v[100005];

/*int absolute(int a)
{
    return a > 0 ? a : -a;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first || (a.first == b.first && absolute(a.second) < absolute(b.second));
}*/

int main()
{
    scanf("%d%d", &n, &w);
    vector<pair<int, int> > planes;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        planes.push_back(make_pair(a, b));
    }
    sort(planes.begin(), planes.end());
    vector<double> left_begin_times, left_end_times, right_begin_times, right_end_times;
    for (int i = 1; i <= n; i++) {
        x[i] = planes[i-1].first;
        v[i] = planes[i-1].second;
        if (x[i] < 0) {
            left_begin_times.push_back(-(double)(x[i]) / (double)(v[i] - w));
            left_end_times.push_back(-(double)(x[i]) / (double)(v[i] + w));
        } else {
            right_begin_times.push_back(-(double)(x[i]) / (double)(v[i] - w));
            right_end_times.push_back(-(double)(x[i]) / (double)(v[i] + w));
        }
        //printf("%.3f %.3f\n", -(double)(x[i]) / (double)(v[i] - w), -(double)(x[i]) / (double)(v[i] + w));
    }
    ans += bpairs(left_end_times, true) - bpairs(left_begin_times, false);
    ans += gpairs(right_begin_times, true) - gpairs(right_end_times, false);
    //for (int i = 0; i < left_end_times.size(); i++) printf("%.3f\n", left_end_times[i]);
    ans += cross_gpairs(left_end_times, right_end_times, true)
        - cross_gpairs(left_begin_times, right_begin_times, false);
    printf("%lld", ans);
    return 0;
}