#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 5050;
int BIT[2*MAXN], barr[2*MAXN];

struct hseg {
    int y, x1, x2;
};

struct vseg {
    int x, y1, y2;
};

vector<vseg> vert;
vector<hseg> hoz;

void upd(int p, int v) {
    for(; p < 2*MAXN; p += (p & -p)) BIT[p] += v;
}

int sum(int p) { 
    int res = 0;
    for(; p > 0; p -= (p & -p)) res += BIT[p];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 5010;
        x2 += 5010;
        if(y1 == y2)
            hoz.push_back({y1, min(x1, x2), max(x1, x2)});
        else
            vert.push_back({x1, min(y1, y2), max(y1, y2)});
    }
    sort(hoz.begin(), hoz.end(), [&](hseg a, hseg b) {
        return a.y > b.y;
    });
    sort(vert.begin(), vert.end(), [&](vseg a, vseg b) {
        return a.y1 > b.y1;
    });

    ll ans = 0;
    for(int i = 0; i < hoz.size(); i++){
        hseg upper = hoz[i];
        fill(BIT, BIT + 2*MAXN, 0);
        fill(barr, barr + 2*MAXN, 0);
        for(auto seg : vert) {
            if(seg.y2 >= upper.y)
                upd(seg.x, 1);
        }
        int pt = 0;
        for(int j = i + 1; j < hoz.size(); j++) {
            hseg lower = hoz[j];
            while(pt < vert.size() && vert[pt].y1 > lower.y) {
                if(vert[pt].y2 >= upper.y)
                    upd(vert[pt].x, -1);
                pt++;
            }
            int l = max(lower.x1, upper.x1), r = min(lower.x2, upper.x2);
            ll amt = 0;
            if(r >= l)
                amt = sum(r) - sum(l - 1);
            ans += (amt)*(amt - 1)/2LL;
        }
    }
    cout << ans << '\n';
}