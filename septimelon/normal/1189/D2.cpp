#include <bits/stdc++.h>

using namespace std;

int n, u, v, val;
vector<int> ansu;
vector<int> ansv;
vector<int> ansx;
vector<vector<pair<int,int>>> a;
vector<int> rl1;
vector<int> rl2;
vector<int> rr1;
vector<int> rr2;
vector<int> rl;
vector<int> rr;
vector<int> rval;
vector<bool> lis;
queue<int> reb;
queue<int> from;
queue<int> liss;

void check() {
    int r1 = reb.front();
    reb.pop();
    int f1 = from.front();
    from.pop();
    int l1 = liss.front();
    liss.pop();
    if (f1 == rl[r1]) {
        if (rl1[r1] == 0) {
            rl1[r1] = l1;
            if (lis[rr[r1]]) return;
            for (int i = 0; i < a[rr[r1]].size(); i++) {
                if (a[rr[r1]][i].second != r1) {
                    reb.push(a[rr[r1]][i].second);
                    from.push(rr[r1]);
                    liss.push(l1);
                }
            }
        }
        else if (rl2[r1] == 0) {
            rl2[r1] = l1;
        }
        return;
    }
    else {
        if (rr1[r1] == 0) {
            rr1[r1] = l1;
            if (lis[rl[r1]]) return;
            for (int i = 0; i < a[rl[r1]].size(); i++) {
                if (a[rl[r1]][i].second != r1) {
                    reb.push(a[rl[r1]][i].second);
                    from.push(rl[r1]);
                    liss.push(l1);
                }
            }
        }
        else if (rr2[r1] == 0) {
            rr2[r1] = l1;
        }
        return;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++) {
        a.push_back(vector<pair<int,int>>());
        rl1.push_back(0);
        rl2.push_back(0);
        rr1.push_back(0);
        rr2.push_back(0);
        rl.push_back(0);
        rr.push_back(0);
        rval.push_back(0);
        lis.push_back(false);
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> val;
        a[u].push_back(pair<int,int>(v,i));
        a[v].push_back(pair<int,int>(u,i));
        rl[i] = u;
        rr[i] = v;
        rval[i] = val;
    }
    if (n == 2) {
        cout << "YES" << endl << "1" << endl;
        cout << "1 2 " << rval[1];
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i].size() == 2) {
            cout << "NO";
            return 0;
        }
        if (a[i].size() == 1) {
            lis[i] = true;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        if (lis[i]) {
            reb.push(a[i][0].second);
            from.push(i);
            liss.push(i);
        }
    }
    while (!reb.empty())
        check();
    for (int i = 1; i < n; i++) {
        if (lis[rl[i]]) {
            ansu.push_back(rl[i]);
            ansv.push_back(rr1[i]);
            ansx.push_back(rval[i]/2);
            ansu.push_back(rl[i]);
            ansv.push_back(rr2[i]);
            ansx.push_back(rval[i]/2);
            ansu.push_back(rr1[i]);
            ansv.push_back(rr2[i]);
            ansx.push_back(0-rval[i]/2);
        }
        else if (lis[rr[i]]) {
            ansu.push_back(rr[i]);
            ansv.push_back(rl1[i]);
            ansx.push_back(rval[i]/2);
            ansu.push_back(rr[i]);
            ansv.push_back(rl2[i]);
            ansx.push_back(rval[i]/2);
            ansu.push_back(rl1[i]);
            ansv.push_back(rl2[i]);
            ansx.push_back(0-rval[i]/2);
        }
        else {
            ansu.push_back(rl1[i]);
            ansv.push_back(rr1[i]);
            ansx.push_back(rval[i]/2);
            ansu.push_back(rl2[i]);
            ansv.push_back(rr2[i]);
            ansx.push_back(rval[i]/2);
            ansu.push_back(rl1[i]);
            ansv.push_back(rl2[i]);
            ansx.push_back(0-rval[i]/2);
            ansu.push_back(rr1[i]);
            ansv.push_back(rr2[i]);
            ansx.push_back(0-rval[i]/2);
        }
    }
    cout << ansu.size() << endl;
    for (int i = 0; i < ansu.size(); i++) {
        cout << ansu[i] << " " << ansv[i] << " " << ansx[i] << endl;
    }
    return 0;
}