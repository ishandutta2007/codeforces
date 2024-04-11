#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > a;

int main(){
    int n;
    long double s;
    cin >> n >> s;

    a.resize(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        a[v].push_back(u);
        a[u].push_back(v);
    }

    int cnt = 0;

    if(n == 2){
        cout << s;
        return 0;
    }

    for(int i = 0; i < n; i++)if(a[i].size() == 1)cnt++;

    cout << setprecision(8) << fixed << s * 2 / cnt;

}