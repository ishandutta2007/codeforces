#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > a;
vector<pair<int, int> > b;

vector<int> c;

int dfs(int v, int num){
    c.push_back(v);

    b[v].first = num;
    int res = 0;
    for(int i = 0; i < a[v].size(); i++){
        int k = dfs(a[v][i], num + 1);
        num += k + 1;
        res += k + 1;
    }

    b[v].second = res + 1;

    //cout << v << ' ' << res << ' ' << b[v].first << endl;

    return res;
}

int main(){
    int n, q;
    cin >> n >> q;

    a = vector<vector<int> >(n);
    for(int i = 1; i < n; i++){
        int p;
        cin >> p;
        a[p - 1].push_back(i);
    }

    b = vector<pair<int, int> >(n, make_pair(0, 0));

    dfs(0, 0);

    for(int i = 0; i < q; i++){
        int u, k;
        cin >> u >> k;
        u--;
        if(b[u].second < k)cout << -1 << endl;
        else cout << c[b[u].first + k - 1] + 1 << endl;
    }
}