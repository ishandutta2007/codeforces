#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> twos;

void filltwos() {
    twos.push_back(1);
    while (twos[twos.size()-1] < (ll)1000000000000000000){
        twos.push_back(twos[twos.size()-1] * 2);
    }
}

queue<int> indq;
queue<int> stepq;
queue<int> fromq;
vector<vector<int>> reb;
vector<int> curs;
int mincir;

void bfs(int ind, int step, int from) {
    //cout << ind << " " << step << " " << from << endl;
    if (curs[ind] >= 0)
        mincir = min(mincir, step + curs[ind]);
    if (curs[ind] >= 0)
        return;
    curs[ind] = step;
    for (int i = 0; i < reb[ind].size(); i++){
        if (reb[ind][i] == from)
            continue;
        indq.push(reb[ind][i]);
        stepq.push(step+1);
        fromq.push(ind);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    filltwos();
    int n;
    cin >> n;
    int delta = 0;
    vector<ll> a;
    ll buf;
    for (int i = 0; i < n; i++){
        cin >> buf;
        if (buf == 0) {
            delta++;
        }
        else {
            a.push_back(buf);
        }
    }
    n -= delta;
    if (n <= 200) {
        reb.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (a[i]&a[j])
                    reb[i].push_back(j);
            }
        }
        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < reb[i].size(); j++) {
                cout << reb[i][j] << " ";
            }
            cout << endl;
        }*/
        mincir = 10000;
        for (int i = 0; i < n; i++) {
            //cout << i << ": ";
            curs.clear();
            curs.resize(n, -10000);
            indq.push(i);
            stepq.push(0);
            fromq.push(-1);
            while (!indq.empty()) {
                bfs(indq.front(), stepq.front(), fromq.front());
                indq.pop();
                stepq.pop();
                fromq.pop();
            }
            //cout << endl;
        }
        if (mincir > n) {
            cout << "-1" << endl;
        }
        else {
            cout << mincir << endl;
        }
    }
    else {
        cout << "3" << endl;
    }
    return 0;
}