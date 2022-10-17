#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 100;

int N;
int perm[MAXN];
bool done[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    int self = -1;
    for (int i = 0; i < N; i++) {
        cin >> perm[i];
        perm[i]--;

        if(perm[i] == i && self == -1)
            self = i;
    }

    if (self != -1) {
        cout << "YES\n";
        for (int i = 0; i < N; i++) 
            if(i != self) {
                cout << self+1 << " " << i+1 << "\n";
            }
        return 0;
    }

    int cyc2 = -1;

    for (int i = 0; i < N; i++) {
        if(perm[perm[i]] == i) {
            cyc2 = i;
            break;
        }
    }

    if(cyc2 == -1) {
        cout << "NO\n";
        return 0;
    }

    vector<pair<int, int>> ans;

    int r1 = cyc2, r2 = perm[r1];
    ans.emplace_back(r1, r2);
    done[r1] = done[r2] = true;

    for (int i = 0; i < N; i++) {
        if(done[i]) continue;        

        vector<int> fam;
        for (int j = i; !done[j]; j = perm[j]) {
            fam.push_back(j);
            done[j] = true;
        }

        if(fam.size() & 1) { cout << "NO\n"; return 0; }

        for (int j = 0; j < fam.size(); j++) {
            if(j&1) ans.emplace_back(r2, fam[j]);
            else ans.emplace_back(r1, fam[j]);
        }
    }

    cout << "YES\n";
    for (auto p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
}