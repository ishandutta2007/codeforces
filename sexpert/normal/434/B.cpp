#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e3 + 5;
int up[MAXN][MAXN], down[MAXN][MAXN], leftt[MAXN][MAXN], rightt[MAXN][MAXN], grid[MAXN][MAXN], n, m;


void calc_hoz(int r) {
    int last = 0;
    for(int i = 1; i <= m; i++) {
        if(grid[r][i] == 0)
            last = i;
        leftt[r][i] = i - last;
    }
    last = m + 1;
    for(int i = m; i >= 1; i--) {
        if(grid[r][i] == 0)
            last = i;
        rightt[r][i] = last - i;
    }
}

void calc_vert(int c) {
    int last = 0;
    for(int i = 1; i <= n; i++) {
        if(grid[i][c] == 0)
            last = i;
        up[i][c] = i - last;
    }
    last = n + 1;
    for(int i = n; i >= 1; i--) {
        if(grid[i][c] == 0)
            last = i;
        down[i][c] = last - i;
    }
}

//ULDR
void print() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << up[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "===\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << leftt[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "===\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << down[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "===\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << rightt[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "~~~~~~~~~~\n";
}

int qry_up(int r, int c) {
    vector<int> le(m + 5), ri(m + 5);
    stack<ii> st;
    for(int i = 1; i <= m; i++) {
        while(st.size() && st.top().first >= up[r][i])
            st.pop();
        if(st.empty()) {
            le[i] = 1;
            st.push({up[r][i], i});
        }
        else {
            le[i] = st.top().second + 1;
            st.push({up[r][i], i});
        }
    }
    st = stack<ii>();
    for(int i = m; i >= 1; i--) {
        while(st.size() && st.top().first >= up[r][i])
            st.pop();
        if(st.empty()) {
            ri[i] = m;
            st.push({up[r][i], i});
        }
        else {
            ri[i] = st.top().second - 1;
            st.push({up[r][i], i});
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        if(le[i] <= c && c <= ri[i])
            ans = max(ans, (ri[i] - le[i] + 1) * up[r][i]);
    }
    return ans;
}

int qry_dn(int r, int c) {
    vector<int> le(m + 5), ri(m + 5);
    stack<ii> st;
    for(int i = 1; i <= m; i++) {
        while(st.size() && st.top().first >= down[r][i])
            st.pop();
        if(st.empty()) {
            le[i] = 1;
            st.push({down[r][i], i});
        }
        else {
            le[i] = st.top().second + 1;
            st.push({down[r][i], i});
        }
    }
    st = stack<ii>();
    for(int i = m; i >= 1; i--) {
        while(st.size() && st.top().first >= down[r][i])
            st.pop();
        if(st.empty()) {
            ri[i] = m;
            st.push({down[r][i], i});
        }
        else {
            ri[i] = st.top().second - 1;
            st.push({down[r][i], i});
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        if(le[i] <= c && c <= ri[i])
            ans = max(ans, (ri[i] - le[i] + 1) * down[r][i]);
    }
    return ans;
}

int qry_le(int r, int c) {
    vector<int> upp(n + 5), dn(n + 5);
    stack<ii> st;
    for(int i = 1; i <= n; i++) {
        while(st.size() && st.top().first >= leftt[i][c])
            st.pop();
        if(st.empty()) {
            upp[i] = 1;
            st.push({leftt[i][c], i});
        }
        else {
            upp[i] = st.top().second + 1;
            st.push({leftt[i][c], i});
        }
    }
    st = stack<ii>();
    for(int i = n; i >= 1; i--) {
        while(st.size() && st.top().first >= leftt[i][c])
            st.pop();
        if(st.empty()) {
            dn[i] = n;
            st.push({leftt[i][c], i});
        }
        else {
            dn[i] = st.top().second - 1;
            st.push({leftt[i][c], i});
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(upp[i] <= r && r <= dn[i])
            ans = max(ans, (dn[i] - upp[i] + 1) * leftt[i][c]);
    }
    return ans;
}

int qry_ri(int r, int c) {
    vector<int> upp(n + 5), dn(n + 5);
    stack<ii> st;
    for(int i = 1; i <= n; i++) {
        while(st.size() && st.top().first >= rightt[i][c])
            st.pop();
        if(st.empty()) {
            upp[i] = 1;
            st.push({rightt[i][c], i});
        }
        else {
            upp[i] = st.top().second + 1;
            st.push({rightt[i][c], i});
        }
    }
    st = stack<ii>();
    for(int i = n; i >= 1; i--) {
        while(st.size() && st.top().first >= rightt[i][c])
            st.pop();
        if(st.empty()) {
            dn[i] = n;
            st.push({rightt[i][c], i});
        }
        else {
            dn[i] = st.top().second - 1;
            st.push({rightt[i][c], i});
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(upp[i] <= r && r <= dn[i])
            ans = max(ans, (dn[i] - upp[i] + 1) * rightt[i][c]);
    }
    return ans;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> grid[i][j];

    for(int r = 1; r <= n; r++)
        calc_hoz(r);

    for(int c = 1; c <= m; c++)
        calc_vert(c);

    //print();
    while(q--) {
        int t, r, c;
        cin >> t >> r >> c;
        if(t == 1) {
            grid[r][c] ^= 1;
            calc_hoz(r);
            calc_vert(c);
            //print();
        }
        else {
            int ans = 0;
            ans = max(ans, qry_up(r, c));
            ans = max(ans, qry_dn(r, c));
            ans = max(ans, qry_le(r, c));
            ans = max(ans, qry_ri(r, c));
            cout << ans << '\n';
        }
    }
}