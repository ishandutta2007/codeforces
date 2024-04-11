#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v[26];

class UnionFind
{
    int par[200002], rank[200002];
    
public:
    UnionFind(int n){
        for(int i = 0; i < n; i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int i){
        if(i == par[i]) return i;
        return par[i] = find(par[i]);
    }
    
    bool same(int i, int j){
        return par[i] == par[j];
    }
    
    void unite(int i, int j){
        if(same(i, j)) return;
        i = find(i), j = find(j);
        if(rank[i] < rank[j]) par[i] = j;
        else{
            par[j] = i;
            if(rank[i] == rank[j]) rank[i]++;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    string s[200005];
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < (int)s[i].size(); j++) v[s[i][j] - 'a'].push_back(i);
    }
    UnionFind uf(n);
    for(int j = 0; j < 26; j++){
        for(int i = 0; i < (int)v[j].size() - 1; i++) uf.unite(v[j][i], v[j][i + 1]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) if(uf.find(i) == i) ans++;
    cout << ans << endl;
}