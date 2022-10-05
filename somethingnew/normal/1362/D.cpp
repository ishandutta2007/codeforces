#include <iostream>
#include <vector>
#include "algorithm"
#include "set"

#define long long long
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n);
    int m;
    cin >> m;
    vector<int> versh;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        int nn;
        cin >> nn;
        versh.push_back(nn);
        nums[nn-1].push_back(i);
    }
    vector<int> ans;
    int nnum = 0;
    vector<int> n1;
    for(auto lst : nums){
        if(nnum) n1.push_back(nnum);
        nnum += 1;
        for(auto i : lst){
            ans.push_back(i);
            set<int> n2;
            for(auto rebro : graph[i]) {
                n2.insert(versh[rebro]);
            }
            for(auto aer : n1){
                if(n2.find(aer) == n2.end()){
                    cout << -1;
                    return 0;
                }
            }
            if(n2.find(nnum) != n2.end()){
                cout << -1;
                return 0;
            }
        }
    }
    for(auto i : ans) cout << i + 1 << ' ';
    return 0;
}