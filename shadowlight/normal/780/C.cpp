/*
ZDRAVSTVUYTE
ESLI VI HOTITE MENYA VZLOMAT'
YA VAM SRAZU SKAZHU
TUT BAGOV NETU
UDACHNOGO VZLOMA
SPASIBO ZA VNIMANIE
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector <vector <int> > gr;
vector <int> color;

int n;
int maxk = 0;

void dfs(int v, int p, int cp) {
    int now_color = 1;
    for (int u : gr[v]) {
        if (u == p) continue;
        while (now_color == color[v] || now_color == cp) now_color++;
        color[u] = now_color;
        now_color++;
    }
    maxk = max(maxk, now_color - 1);
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v, color[v]);
    }
}

int main() {
    cin >> n;
    gr.resize(n);
    color.resize(n, 0);
    for (int i = 1; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        gr[l].push_back(r);
        gr[r].push_back(l);
    }
    color[0] = 1;
    dfs(0, -1, -1);
    cout << maxk << endl;
    for (int i = 0; i < n; i++) {
        cout << color[i] << " ";
    }
}