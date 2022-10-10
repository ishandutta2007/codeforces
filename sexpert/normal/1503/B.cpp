#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

int gr[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ii> ev, od;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if((i + j) % 2)
                od.push_back({i, j});
            else
                ev.push_back({i, j});
        }
    }
    int pev = 0, pod = 0, mov = 0;
    while(pev < ev.size() && pod < od.size()) {
        int a;
        cin >> a;
        if(a == 1) {
            cout << "2 " << od[pod][0] << " " << od[pod][1] << endl;
            gr[od[pod][0]][od[pod][1]] = 2;
            pod++;
        } 
        else {
            cout << "1 " << ev[pev][0] << " " << ev[pev][1] << endl;
            gr[ev[pev][0]][ev[pev][1]] = 1;
            pev++;
        }
        mov++;
    }
    while(mov < n * n) {
        ii u;
        if(pev < ev.size())
            u = ev[pev++];
        else
            u = od[pod++];
        int a;
        cin >> a;
        for(int d = 1; d <= 3; d++) {
            if(d == a)
                continue;
            if(d == gr[u[0] - 1][u[1]] || d == gr[u[0] + 1][u[1]] || d == gr[u[0]][u[1] - 1] || d == gr[u[0]][u[1] + 1])
                continue;
            gr[u[0]][u[1]] = d;
            cout << d << " " << u[0] << " " << u[1] << endl;
            break;
        }
        mov++;
    }
}