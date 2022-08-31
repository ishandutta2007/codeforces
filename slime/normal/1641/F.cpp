//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 3
#define S 20
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
#define db double
const int maxn = 50005;

int n, l, k;
struct pt {
    db x, y;
    pt(){}
    pt(db a, db b) {
        x = a, y = b;
    }
    pt operator + (pt a) {
        return pt(x + a.x, y + a.y);
    }
    pt operator - (pt a)  {
        return pt(x - a.x, y - a.y);
    }
    pt operator * (db a) {
        return pt(x * a, y * a);
    }
    db operator * (pt a) {
        return x * a.x + y * a.y;
    }
    db dis() {
        return x * x + y * y;
    }
};
pt cent(pt a, pt b, pt c) {
    pt cr = (c - a); 
    cr = pt(-cr.y, cr.x); // c + k cr
    pt g = b - a; db nd = (b * g - c * g) / (cr * g);
    pt h = c + cr * nd;
    h = (h + a) * 0.5;
    return h;
}
db ans = 1e18;
const db eps = 1e-10;
void cal(vector<pt> h) {
    if (h.size() < k) return ;
    auto chk = [&](pt a, db r) -> int
    {
        r *= (1 + eps);
        if (r > ans)
            return 0;
        int cnt = 0;
        for (auto v : h)
        {
            db h = (a - v).dis();
            if (h <= r) 
                cnt += 1;
        }
        if (cnt >= k)
        {
            chkmin(ans, r);
            return 1;
        }
        return 0;
    };
    for (int i = 0; i < h.size(); i++)
        for (int j = i + 1; j < h.size(); j++) {
            pt cen = (h[i] + h[j]) * 0.5;
            db cd = (cen - h[i]).dis();
            if (cd > ans) continue;
            if (chk(cen, cd + eps)) continue;
            for (int k = j + 1; k < h.size(); k++){
                pt cen = cent(h[i], h[j], h[k]);
                chk(cen, (cen - h[i]).dis() + eps);
            }
        }
}
pt f[maxn];
pi lab[maxn];
int x[maxn], y[maxn];
unordered_map<ll, unordered_set<int> > h;
unordered_map<ll, int > cs;
ll hh(pi x) {
    ll cur = x.fi; return (cur << 30) | x.se;
}
void ins(int i, int tp) {
    if (tp == 1)
        h[hh(lab[i])].insert(i);
    else h[hh(lab[i])].erase(i);
}
void callb(int h) {
    for (int i = 1; i <= n; i++)
        lab[i] = mp(x[i] >> h, y[i] >> h);
}
void upd(pi x, int nid) {
    int ss[3][3] = {0};
    int fl[3][3] = {0};
    vi uh[3][3];
    auto uu = [&](int l1, int r1, int l2, int r2) {
        int tot = 0;
        for (int i = l1; i <= r1; i++)
            for (int j = l2; j <= r2; j++)
                tot += ss[i][j];
        if (tot < k) return ;
        vector<pt> cur;
        for (int i = l1; i <= r1; i++)
            for (int j = l2; j <= r2; j++)
                for (auto v : uh[i][j])
                    cur.pb(f[v]);
        cal(cur);
    };

    int ts = 0;
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j <= 2; j++) {
            pi cur = mp(x.fi + i - 1, x.se + j - 1);
            if (!h.count(hh(cur))) continue;
            for (auto v : h[hh(cur)]) {
                if ((f[nid] - f[v]).dis() <= ans * 4) {
                    ts += 1;
                    uh[i][j].pb(v);
                    ss[i][j] += 1;
                }
            } 
        }
    if (ts < k) return ;
    for (int i = 0; i <= 2; i += 2)
        for (int j = 0; j <= 2; j += 2) 
            if (ss[i][j] || (ss[1][j] && ss[i][1])) {
                fl[i][j] = 1;
                uu(min(1, i), max(1, i), min(1, j), max(1, j));
            }
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j <= 2; j++) {
            if ((i == 1) == (j == 1)) continue;
            if ((fl[0][j] || fl[2][j]) && (i == 1)) continue;
            if ((fl[0][i] || fl[2][i]) && (j == 1)) continue;
            if (!ss[i][j]) continue;
            fl[i][j] = 1;
            uu(min(1, i), max(1, i), min(1, j), max(1, j));
        }
    int cnt = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cnt += fl[i][j];
    if (!cnt) uu(1, 1, 1, 1);
}
int main() {
    int t;
    cin >> t;
    int s = 0;
    while (t--) {
        cin >> n >> l >> k;
        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i], x[i] += 1e8, y[i] += 1e8, f[i] = pt(x[i], y[i]);
        int mx = k * 4;
        int lb = 0;
        
        for (int j = 28; j >= 0; j--) {
            int cl = clock();
            callb(j);
            cs.clear();
            cs.reserve(n);
            int flag = 1;
            for (int i = 1; i <= l && flag; i++) {
                cs[hh(lab[i])] += 1;
                if (cs[hh(lab[i])] >= mx)
                {
                    flag = 0;
                    break;
                }
            }
            for (int i = l + 1; i <= n && flag; i++) {
                cs[hh(lab[i - l])] -= 1;
                cs[hh(lab[i])] += 1;
                if (cs[hh(lab[i])] >= mx)
                    flag = 0;
            }
            if (flag) {
                lb = j;
                break;
            }
            s += clock() - cl;
        }
        callb(lb);
        h.clear();
        ans = 1e18;
        for (int i = 1; i <= l; i++)
            h[hh(lab[i])].insert(i), upd(lab[i], i);
        for (int i = l + 1; i <= n; i++) {
            h[hh(lab[i - l])].erase(i - l);
            h[hh(lab[i])].insert(i);
            upd(lab[i], i);
        }
        printf("%.10lf\n", (double)sqrt(ans));
    }
    cerr << 1.0 * s / CLOCKS_PER_SEC << endl;
    return (0-0); //<3
}
/*
1
8 3 2
0 3
1 0
0 2
1 1
0 1
1 2
0 0
1 3
*/