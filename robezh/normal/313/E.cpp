#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int n, m;
int res[N];
int fa[N], fb[N];
deque<int> Sa, Sb;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int a; cin >> a; fa[a]++;
    }
    for(int i = 0; i < n; i++) {
        int a; cin >> a; fb[a]++;
    }
    for(int i = m - 1; i >= 0; i--) {
        while(fb[m - 1 - i]) {
            Sb.push_back(m - 1 - i);
            fb[m - 1 - i]--;
        }
        while(fa[i]) {
            if(Sb.empty()) Sa.push_back(i);
            else {
                res[Sb.back() + i] ++;
                Sb.pop_back();
            }
            fa[i]--;
        }
    }
    while(!Sa.empty()) {
        res[(Sa.front() + Sb.back()) % m] ++;
        Sa.pop_front();
        Sb.pop_back();
    }
    for(int i = m - 1; i >= 0; i--) {
        while(res[i]) {
            cout << i << " ";
            res[i]--;
        }
    }

}