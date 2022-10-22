#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 1e6;
long long n, m, k, size1 = 0;
vector <int> parent(INF, -1);
vector <int> size(INF, 0);
vector <vector <int> > used(1001, vector <int> (1001, 0));
vector <vector <int> > used1(1001, vector <int> (1001, 0));
void create(int x) {
    parent[x] = x;
    size[x] = 1;
}

int find_p(int v) {
    if (parent[v] == -1) return -1;
    if (parent[v] == v) return v;
    return parent[v] = find_p(parent[v]);
}

void unit(int v1, int v2) {
    if (v1 == v2) return;
    //v1 = find_p(v1);
    //v2 = find_p(v2);
    if (size[v1] > size[v2]) swap(v1, v2);
    parent[v1] = v2;
    size[v2] += size[v1];
}
bool ans_flag = 0;
vector <vector <int> > g(1001, vector <int> (1001, 0));
vector <vector <int> > g1(1001, vector <int> (1001, 0));
void dfs(int k, long long &l, int x, int y) {
    if (g[x][y] < k) return;
    if (l <= 0) {
        ans_flag = 1;
        return;
    }
   // cout << x << " " << y << endl;
    l--;
    used1[x][y] = 1;
    g1[x][y] = k;
    if (x < n - 1 && !used1[x + 1][y]) {
        dfs(k, l, x + 1, y);
        if (ans_flag) return;
    }
    if (y < m - 1 && !used1[x][y + 1]) {
        dfs(k, l, x, y + 1);
        if (ans_flag) return;
    }
    if (y > 0 && !used1[x][y - 1]) {
        dfs(k, l, x, y - 1);
        if (ans_flag) return;
    }
    if (x > 0 && !used1[x - 1][y]) {
        dfs(k, l, x - 1, y);
        if (ans_flag) return;
    }

}

int main() {
    cin >> n >> m >> k;
    vector <pair <int, int> > data;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c;
            cin >> c;
            data.push_back({c, m * i + j});
            g[i][j] = c;
        }
    }
    sort(data.rbegin(), data.rend());
    for (int i = 0; i < data.size(); i++) {
        size1 = 0;
        create(data[i].second);
        size1 = max(size1, (long long) 1);
        int v1 = data[i].second;
        if (data[i].second >= m) {
            int v2 = find_p(data[i].second - m);
            if (v2 != -1) {
                //cout << v1 << " " << v2 << endl;
                unit(v1, v2);
                size1 = max(size1, (long long) max(size[v1], size[v2]));
            }
        }
        v1 = find_p(v1);
        if (data[i].second % m != 0) {
            int v2 = find_p(data[i].second - 1);
            if (v2 != -1) {
              //  cout << v1 << " " << v2 << endl;
                unit(v1, v2);
                size1 = max(size1, (long long) max(size[v1], size[v2]));
            }
        }
        v1 = find_p(v1);
        if (data[i].second % m != m - 1) {
            int v2 = find_p(data[i].second + 1);
            if (v2 != -1) {
             //   cout << v1 << " " << v2 << endl;
                unit(v1, v2);
                size1 = max(size1, (long long) max(size[v1], size[v2]));
            }
        }
        v1 = find_p(v1);
        if (data[i].second < (n - 1) * m) {
            int v2 = find_p(data[i].second + m);
            if (v2 != -1) {
               // cout << v1 << " " << v2 << endl;
                unit(v1, v2);
                size1 = max(size1, (long long) max(size[v1],  size[v2]));
            }
        }
        //cout << data[i].first << " " << size1  << " " << data[i].second << endl;
        if (k % data[i].first == 0 && (long long) data[i].first * size1 >= k) {
            cout << "YES" << endl;
            long long z = k / data[i].first;
          //  cout << z << endl;
            dfs(data[i].first, z, data[i].second / m, data[i].second % m);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << g1[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }
    }
    cout << "NO";
    return 0;
}