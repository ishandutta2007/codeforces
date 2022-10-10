#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int BL = 205, BS = 500;
const int MAXN = 1e5 + 10;
int last = 0, n;

int cnt[BL][MAXN];
vi blocks[BL], v;

int get(int p) {
    for(int i = 0; i < BL; i++) {
        if(p < blocks[i].size())
            return blocks[i][p];
        else
            p -= blocks[i].size();
    }
}

void rem(int p) {
    for(int i = 0; i < BL; i++) {
        if(p < blocks[i].size()) {
            cnt[i][blocks[i][p]]--;
            blocks[i].erase(blocks[i].begin() + p);
            return;
        }
        else
            p -= blocks[i].size();
    }
}

void add(int p, int va) {
    for(int i = 0; i < BL; i++) {
        if(p < blocks[i].size()) {
            cnt[i][va]++;
            blocks[i].insert(blocks[i].begin() + p, va);
            return;
        }
        else
            p -= blocks[i].size();
    }
}

void rebuild() {
    for(int i = 0; i < BL; i++) {
        for(auto x : blocks[i])
            cnt[i][x]--;
        blocks[i].clear();
    }
    for(int i = 0; i < n; i++) {
        blocks[i/BS].push_back(v[i]);
        cnt[i/BS][v[i]]++;
    }
}

void print() {
    for(int i = 0; i < BL; i++)
        for(auto x : blocks[i])
            cout << x << " ";
    cout << endl;
}

int qry(int l, int r, int k) {
    int st = 0, ans = 0;
    for(int i = 0; i < BL; i++) {
        if(st > r)
            break;
        if(st + blocks[i].size() - 1 < l) {
            st += blocks[i].size();
            continue;
        }
        if(l <= st && st + blocks[i].size() - 1 <= r)
            ans += cnt[i][k];
        else {
            for(int j = 0; j < blocks[i].size(); j++) {
                if(st + j >= l && st + j <= r && blocks[i][j] == k) {
                    ans++;
                }
            }
        }
        st += blocks[i].size();
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    v.resize(n);
    for(auto &x : v)
        cin >> x;
    rebuild();

    int q, prev = 0;
    cin >> q;
    while(q--) {
        //print();
        int t, l1, r1, k1 = 0;
        cin >> t >> l1 >> r1;
        if(t == 2)
            cin >> k1;
        int l = (l1 + last - 1) % n + 1;
        int r = (r1 + last - 1) % n + 1;
        int k = (k1 + last - 1) % n + 1;
        if(l > r)
            swap(l, r);
        if(t == 2) {
            last = qry(l - 1, r - 1, k);
            cout << last << '\n';
        }
        else {
            int x = get(r - 1);
            rem(r - 1);
            add(l - 1, x);
            prev++;
        }
        if(prev == 300) {
            prev = 0;
            v.clear();
            for(int i = 0; i < BL; i++)
                for(auto x : blocks[i])
                    v.push_back(x);
            rebuild();
        }
    }
}