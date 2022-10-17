#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int MOD = 1e9 + 7;
int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return 1ll * a * b % MOD; }

#define cf(i) expr[i].front()
#define cb(i) expr[i].back()

vvi read(int N, int M) {
    vvi expr(N);
    vvi appear(M + 1);

    for (int i = 0; i < N; i++) {
        int sz;
        cin >> sz;

        for (int j = 0; j < sz; j++) {
            int var;
            cin >> var;
            expr[i].push_back(var);
            appear[abs(var)].push_back(i);
        }
    }

    vvi result;
    vector<bool> placed(N);

    for (int i = 0; i < N; i++) {
        if (placed[i]) continue;
        if (appear[abs(cf(i))].size() > appear[abs(cb(i))].size())
            swap(cf(i), cb(i));

        int loc = i;
        int bef = result.size();

        while (true) {
            placed[loc] = true;
            result.push_back(expr[loc]);

            int link = abs(cb(loc));
            int nbr = -1;
            if (appear[link].size() == 2) {
                nbr = appear[link][0] + appear[link][1] - loc;
                if (placed[nbr]) nbr = -1;
            }

            if (nbr == -1) {
                bool rev = false;
                link = abs(cf(i));
                if (appear[link].size() == 2) {
                    nbr = appear[link][0] + appear[link][1] - i;
                    if (!placed[nbr]) {
                        rev = true;
                        auto sta = result.begin() + bef;
                        reverse(sta, result.end());
                        for (auto it = sta; it != result.end(); it++) {
                            reverse(it->begin(), it->end());
                        }
                        loc = i;
                    }
                }
                if (!rev) break;
            }
                
            if (abs(expr[nbr].front()) != link)
                swap(expr[nbr].front(), expr[nbr].back());

            loc = nbr;
        }
    }

    return result;
}

array<int, 2> brute(vvi expr, vector<array<int, 2>> mid) {
    vi vars;
    for (vi &cl : expr)
        for (int var : cl)
            vars.push_back(abs(var));
    sort(vars.begin(), vars.end());
    vars.erase(unique(vars.begin(), vars.end()), vars.end());

    for (vi &cl : expr)
        WATCHC(cl);

    array<int, 2> res = { 0, 0 };

    for (int m = 0; m < 1 << (vars.size()); m++) {
        map<int, bool> val;
        for (int i = 0; i < vars.size(); i++) {
            val[vars[i]] = (m >> i)&1;
            //cout << vars[i] << "=" << val[vars[i]] << " ";
        }
        //cout << endl;

        bool par = 0;
        for (vi &cl : expr) {
            bool clv = 0;
            for (int var : cl)
                clv |= val[abs(var)] ^ (var < 0);
            par ^= clv;
        }
        //WATCH(par);

        if (mid.size() > 0) {
            array<int, 2> ways = mid[2 * val[abs(expr[0].back())] + val[abs(expr[1].front())]];
            res[par] = sum(res[par], ways[0]);
            res[!par] = sum(res[!par], ways[1]);
        } else {
            res[par]++;
        }

        //WATCHC(res);
    }

    return res;
}

vector<array<int, 2>> solve(vvi &expr, int i, int j) {
    vector<array<int, 2>> res(4, { 0, 0 });
    if (i == j) {
        for (int a = 0; a < 2; a++) 
            for (int b = 0; b < 2; b++)
                res[2 * a + b][(a ^ (expr[i][0] < 0)) | (b ^ (expr[i][1] < 0))]++;
    } else {
        vector<array<int, 2>> rem = solve(expr, i + 1, j);
        for (int lv = 0; lv < 2; lv++)
            for (int sn = 0; sn < 2; sn++)
                for (int op = 0; op < 2; op++) {
                    int way = rem[2 * sn + lv][op];
                    for (int fs = 0; fs < 2; fs++) {
                        bool par = op ^ ((fs ^ (expr[i][0] < 0)) | (sn ^ (expr[i][1] < 0)));
                        res[2 * fs + lv][par] = sum(res[2 * fs + lv][par], way);
                    }
                }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;
    vvi expr = read(N, M);

    array<int, 2> ans = { 1, 0 };

    for (int i = 0; i < N; ) {
        int j = i;
        while (j + 1 < N && abs(cb(j)) == abs(cf(j+1)))
            j++;

        for (int k = i; k <= j; k++)
            WATCHC(expr[k]);

        array<int, 2> here = { 0, 0 };

        if (i == j) {
            here = brute({ expr[i] }, {});
        } else if (i + 1 == j) {
            here = brute({ expr[i], expr[j] }, {});
        } else {
            if (expr[i+1][0] < 0) {
                expr[i].back() *= -1;
                expr[i+1][0] *= -1;
            }
            if (expr[j-1][1] < 0) {
                expr[j-1][1] *= -1;
                expr[j].front() *= -1;
            }
            here = brute( { expr[i], expr[j] }, solve(expr, i + 1, j - 1) );
        }

        array<int, 2> upd = { 0, 0 };
        for (int pp = 0; pp < 2; pp++)
            for (int ph = 0; ph < 2; ph++)
                upd[pp^ph] = sum(upd[pp^ph], prod(ans[pp], here[ph]));
        ans = upd;

        WATCHC(ans);

        i = j + 1;
    }

    map<int, bool> app;
    for (vi &cl : expr)
        for (int var : cl)
            app[abs(var)] = true;
    for (int i = 1; i <= M; i++)
        if (!app[i])
            ans[1] = prod(ans[1], 2);

    cout << ans[1] << "\n";
    return 0;
}