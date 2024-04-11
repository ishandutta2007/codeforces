#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int stin[8005], uwu[8005], owo[8005], n;
bitset<8005> mat[8005];
vector<int> p1, p2;

void add(vector<int> &v, int x) {
    if(v.empty()) {
        v.push_back(x);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(mat[x][v[i]]) {
            v.insert(v.begin() + i, x);
            return;
        }
    }
}

int transfer() {
    if(p1.empty() || p2.empty())
        return -1;
    int u = p1.back();
    for(int i = 0; i < p2.size(); i++) {
        if(mat[p2[i]][u])
            return i;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < (n / 4); j++) {
            int d;
            if(s[j] >= '0' && s[j] <= '9')
                d = s[j] - '0';
            else
                d = 10 + s[j] - 'A';
            for(int b = 0; b < 4; b++)
                mat[i][4*j + 3 - b] = (d & (1 << b)) >> b;
        }
    }
    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat[i][j];
        }
        cout << '\n';
    }*/
    for(int p = 0; p < n; p++) {
        while(true) {
            int i = transfer();
            if(i == -1)
                break;
            int x = p2[i];
            p2.erase(p2.begin() + i);
            add(p1, x);
        }
        bool out = false;
        for(auto x : p1)
            if(mat[p][x])
                out = true;
        if(!out) {
            p1.push_back(p);
            continue;
        }
        if(mat[p][p1.back()]) {
            add(p1, p);
            continue;
        }
        out = false;
        for(auto x : p2)
            if(mat[p][x])
                out = true;
        if(!out) {
            p2.push_back(p);
            continue;
        }
        add(p2, p);
    }
    while(true) {
        int i = transfer();
        if(i == -1)
            break;
        int x = p2[i];
        p2.erase(p2.begin() + i);
        add(p1, x);
    }
    /*for(auto x : p1)
        cout << x << " ";
    cout << '\n';
    for(auto x : p2)
        cout << x << " ";
    cout << '\n';*/
    int cnt[5];
    memset(cnt, 0, sizeof cnt);
    cnt[1] = n*(n - 1)/2;
    vector<int> sts;
    sts.push_back(0);
    for(int i = 0; i < p1.size(); i++) {
        int v = p1[i];
        for(int j = 0; j < p2.size(); j++) {
            if(mat[p2[j]][v]) {
                stin[i] = j;
                sts.push_back(j);
                break;
            }
            if(j + 1 == p2.size()) {
                stin[i] = p2.size();
                sts.push_back(p2.size());
            }
        }
    }
    for(int i = 0; i < p1.size(); i++) {
        for(int j = i + 1; j < p1.size(); j++) {
            if(stin[i] < stin[j])
                cnt[2]++;
        }
    }

    for(int i = 0; i < p1.size(); i++)
        for(int j = 0; j < p2.size(); j++)
            uwu[i] += mat[p2[j]][p1[i]];

    for(int i = 0; i < p1.size(); i++) {
        for(int j = 0; j < p2.size(); j++) {
            if(!mat[p1[i]][p2[j]])
                cnt[2]++;
            uwu[i] -= mat[p2[j]][p1[i]];
            if((mat[p1[i]][p2[j]]) && (uwu[i] || owo[j]))
                cnt[2]++;
            owo[j] += mat[p2[j]][p1[i]];
        } 
    }

    sts.push_back(p2.size());
    sort(sts.begin(), sts.end());
    //cout << cnt[2] << endl;
    cnt[2] += (int)(p2.size())*((int)p2.size() - 1)/2;
    sts.erase(unique(sts.begin(), sts.end()), sts.end());
    for(int i = 0; i + 1 < sts.size(); i++) {
        int waturr = sts[i + 1] - sts[i];
        cnt[2] -= waturr * (waturr - 1)/2;
    }

    int mn = n + 1;
    for(int j = (int)p2.size() - 1; j >= 0; j--) {
        for(int i = 0; i < p1.size(); i++)
            if(mat[p2[j]][p1[i]])
                mn = min(mn, i);
        if(mn == n + 1) {
            cnt[4] += j;
            cnt[4] += p1.size();
            continue;
        }
        cnt[4] += mn;
    }

    for(int i = 0; i < p1.size(); i++)
        cnt[4] += min(i, mn);

    cnt[3] = n*(n - 1) - cnt[1] - cnt[2] - cnt[4];
    //cout << cnt[1] << " " << cnt[2] << " " << cnt[3] << " " << cnt[4] << endl;
    ll ans = cnt[1] + 2*cnt[2] + 3*cnt[3] + (ll)(614*n)*cnt[4];
    cout << ans << '\n';
}