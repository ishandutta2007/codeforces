#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <long long> a;
vector <vector <pair <long long, long long> > > gr;
long long sum = 0;
void dfs(long long v, bool op, long long path) {
    if (path < 0) {
        path = 0;
    }
    bool new_op = op;
    if (a[v] < path) {
        new_op = 1;
    }
    if (new_op) {
        sum++;
    }
    for (long long i = 0; i < gr[v].size(); i++) {
        long long u = gr[v][i].first, w = gr[v][i].second;
        dfs(u, new_op, path + w);
    }
    //cout << v << " " << sum << endl;
}

int main() {
    long long n;
    cin >> n;
    a.resize(n, 0);
    gr.resize(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (long long i = 1; i < n; i++) {
        long long par, w;
        cin >> par >> w;
        par--;
        gr[par].push_back({i, w});
    }
    dfs(0, 0, 0);
    cout << sum << endl;
}