#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

const int N = 5e6;

string s;
int n, l, r, ans, res_l, res_r, mx_l, mx_r;
int f1[N], f2[N];
int t[N][2], m;

void change(int num, int v, int L, int R, int pos, int val) {
    //if (pos == 63)
        //cerr << v << " " << L << " " << R << "\n";
    if (R - L == 1) {
        t[v][num] = val;
        /*if (v == 210) {
            cerr << pos << " " << val << " e\n";
            cerr << L << " " << R << " e\n";
        }*/
        return;
    }
    int M = (L + R) / 2;
    if (pos < M)
        change(num, v * 2 + 1, L, M, pos, val);
    else
        change(num, v * 2 + 2, M, R, pos, val);
    t[v][num] = max(t[v * 2 + 1][num], t[v * 2 + 2][num]);
    return;
}

int get_mx(int num, int v, int L, int R, int lg, int rg) {
    //cerr << v << " " << L << " " << R << " " << lg << " " << rg << " res= ";
    if (R <= lg || L >= rg) {
        //cerr << -N << "\n";
        return -N;
    }
    if (R <= rg && L >= lg) {
        //cerr << t[v][num] << "\n";
        return t[v][num];
    }
    //cerr << "    kog\n";
    int M = (L + R) / 2;
    return max(get_mx(num, v * 2 + 1, L, M, lg, rg), get_mx(num, v * 2 + 2, M, R, lg, rg));
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++) {
        f1[i + 1] = f1[i];
        if (s[i] == ')')
            f1[i + 1]++;
        else
            f1[i + 1]--;
    }

    for (int i = 0; i < N - 3; i++)
        t[i][0] = t[i][1] = -N;

    for (int i = s.length() - 1; i >= 0; i--) {
        f2[i] = f2[i + 1];
        if (s[i] == '(')
            f2[i]++;
        else
            f2[i]--;
    }

    for (int i = 0; i <= n; i++) {
        //if (i >= 63)
          //  cout << f1[i] << " ";
        change(0, 0, 0, n + 1, i, f1[i]);
        change(1, 0, 0, n + 1, i, f2[i]);
    }
    //return 0;
    //cout << "\n";

    /*for (int i = 0; i <= n * 4; i++)
        cout << t[i][1] << " ";
    cout << "\n";*/

    //cerr << get_mx(1, 0, 0, n + 1, 0, 1) << "\n";

    //mx_l = get_mx(0, 0, 0, n + 1, 64, 76);
    //return 0;

    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &l, &r);
        l--;
        r;
        ans = r - l;

        //for (int i = l; i < r; i++)
        //    cout << s[i];
        //cout << "\n";

        res_l = f1[l];
        res_r = f2[r];

        mx_r = get_mx(1, 0, 0, n + 1, l, r + 1);
        mx_l = get_mx(0, 0, 0, n + 1, l, r + 1);


        //cerr << res_l << " " << mx_l << "  l\n";
        //cerr << res_r << " " << mx_r << "  r\n";

        ans -= mx_l - res_l;
        ans -= mx_r - res_r;

        printf("%d\n", ans);
    }
    return 0;
}