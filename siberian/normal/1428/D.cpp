#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(a) a.begin(), a.end()

using namespace std;

template<typename T1, typename T2> inline void chkmin(T1& x, const T2& y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1& x, const T2& y) {if (x < y) x = y;}

const int N = 1e5 + 10;
int n;
int a[N];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void no() {
    cout << "-1\n";
    exit(0);
}

set<pair<int, int>> ans;

void addPt(int x, int y) {
    if (x < 0 || x > n || y < 0 || y > n) no();
    ans.insert({x, y});
}

int nxt[N];
bool used[N];

void makeMatching() {
    vector<int> pos1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) continue;
        if (a[i] == 1) {
            pos1.push_back(i);
        }
        if (a[i] == 2) {
            if (pos1.empty()) no();
            nxt[i] = pos1.back();
            used[pos1.back()] = true;
            pos1.pop_back();
        }
    }
    vector<int> pos;

    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) continue;
        if (used[i]) continue;
        
        if (a[i] <= 2) {
            pos.push_back(i);
            continue;
        }

        if (a[i] == 3) {
            if (pos.empty()) no();
            nxt[i] = pos.back();
            //used[nxt[i]] = true;
            pos.pop_back();
            pos.push_back(i);
        }
    }

    /*cout << "nxt = " << endl;
    for (int i = 0; i < n; ++i) {
        cout << nxt[i] << " ";
    }
    cout << endl;*/
}

int myY[N];

void makeAns() {
    fill(myY, myY + n, -1);

    int now = n;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 2) continue;
        myY[i] = now;
        myY[nxt[i]] = now;
        addPt(i + 1, now);
        addPt(nxt[i] + 1, now);
        --now;
    }

    /*cout << "myY = " << endl;
    for (int i = 0; i < n; ++i) {
        cout << myY[i] << " ";
    }
    cout << endl;*/

    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        if (a[i] != 1) continue;
        myY[i] = now;
        addPt(i + 1, now);
        --now;
    }

    /*cout << "myY = " << endl;
    for (int i = 0; i < n; ++i) {
        cout << myY[i] << " ";
    }
    cout << endl;*/

    for (int i = n - 1; i >= 0; --i) {
        if (a[i] != 3) continue;
        assert(myY[nxt[i]]);
        myY[i] = now;
        addPt(i + 1, now);
        addPt(nxt[i] + 1, now);
        --now;   
    }
}

void run() {
    makeMatching();
    makeAns();
}

void write() {
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i.second << " " << i.first << "\n"; 
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.setf(ios::fixed), cout.precision(20);
    read();
    run();
    write();
    return 0;
}