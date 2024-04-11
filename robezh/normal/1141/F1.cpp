#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1505;
typedef pair<int, int> P;

struct sumP {
    ll sum;
    int l, r;
};

int n;
int a[N];
int psum[N];
vector<sumP> p;
int f_res = 0;
vector<P> fp;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], psum[i] = psum[i-1] + a[i];
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            p.push_back({psum[j] - psum[i-1], i, j});
        }
    }
    sort(p.begin(), p.end(), [](const sumP &p1, const sumP &p2) {
        return (p1.sum != p2.sum) ? p1.sum < p2.sum : p1.r < p2.r;
    });
    int r = 0;
    for(int i = 0; i < p.size(); i = r) {
        while(r < p.size() && p[r].sum == p[i].sum) r++;
        int curl = -1;
        int res = 0;
        vector<P> ps;
        for(int j = i; j < r; j++) {
            if(p[j].l <= curl) continue;
            res++;
            ps.push_back({p[j].l, p[j].r});
            curl = p[j].r;
        }
        if(res > f_res) {
            f_res = res;
            fp = ps;
        }
    }
    cout << f_res << endl;
    for(const auto &p : fp) cout << p.first << " " << p.second << endl;
}