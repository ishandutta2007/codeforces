#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

vector<int> G[N];
int n, s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        if(G[i].size() == 1) cnt++;
    }
    double res = (double)s / cnt * 2;
    cout << fixed << setprecision(10) << res << endl;
}