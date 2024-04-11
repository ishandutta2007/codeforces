#include <bits/stdc++.h>
using namespace std;

int a[105], ch[105], hp[105], mov[105];
vector<int> ans;
int n, m;

bool go1(int i, int j) {
    int cur = hp[ch[i]];
    if(i > j)
        return true;
    for(int k = i + 1; k <= j; k++) {
        cur += a[k];
        if(cur < 0)
            return false;
    }
    return true;
}

bool go2(int i, int j) {
    int cur = hp[ch[i]];
    if(i < j)
        return true;
    for(int k = i - 1; k >= j; k--) {
        cur += a[k];
        if(cur < 0)
            return false;
    }
    return true;
}

bool solve1(int p) {
    ans.clear();
    int pr = p;
    memset(mov, 0, sizeof mov);
    int lft = 0;
    while(true) {
        bool done = true;
        for(int i = 1; i <= p; i++)
            if(ch[i] && !mov[i]) {
                done = false;
                lft = 1;
            }
        if(done)
            break;
        bool added = false;
        for(int i = 1; i <= p; i++) {
            if(ch[i] && !mov[i] && go1(i, pr)) {
                ans.push_back(ch[i]);
                mov[i] = 1;
                pr = i;
                added = true;
                break;
            }
        }
        if(!added)
            return false;
    }
    pr = p + lft;
    while(true) {
        bool done = true;
        for(int i = n; i >= p + lft; i--)
            if(ch[i] && !mov[i])
                done = false;
        if(done)
            break;
        bool added = false;
        for(int i = n; i >= p + lft; i--) {
            if(ch[i] && !mov[i] && go2(i, pr)) {
                ans.push_back(ch[i]);
                mov[i] = 1;
                pr = i;
                added = true;
                break;
            }
        }
        if(!added)
            return false;
    }
    return true;
}

bool solve2(int p) {
    ans.clear();
    memset(mov, 0, sizeof mov);
    int pr = p;
    int lft = 0;
    while(true) {
        bool done = true;
        for(int i = n; i >= p; i--)
            if(ch[i] && !mov[i]) {
                done = false;
                lft = 1;
            }
        if(done)
            break;
        bool added = false;
        for(int i = n; i >= p; i--) {
            if(ch[i] && !mov[i] && go2(i, pr)) {
                ans.push_back(ch[i]);
                mov[i] = 1;
                pr = i;
                added = true;
                break;
            }
        }
        if(!added)
            return false;
    }
    pr = p - lft;
    while(true) {
        bool done = true;
        for(int i = 1; i <= p - lft; i++)
            if(ch[i] && !mov[i])
                done = false;
        if(done)
            break;
        bool added = false;
        for(int i = 1; i <= p - lft; i++) {
            if(ch[i] && !mov[i] && go1(i, pr)) {
                ans.push_back(ch[i]);
                mov[i] = 1;
                pr = i;
                added = true;
                break;
            }
        }
        if(!added)
            return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int s, h;
        cin >> s >> h;
        ch[s] = i;
        hp[i] = h;
    }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) {
        if(solve1(i)) {
            cout << i << '\n';
            for(auto x : ans)
                cout << x << " ";
            cout << '\n';
            return 0;
        }
        if(solve2(i)) {
            cout << i << '\n';
            for(auto x : ans)
                cout << x << " ";
            cout << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}