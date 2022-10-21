#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500, INF = (int)1e9 + 500;
typedef pair<int, int> P;

int n,m;
vector<int> num[N];
vector<P> lev[N];
int nsum[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int s, r;
        cin >> s >> r;
        s--;
        num[s].push_back(r);
    }
    int res = 0, sum = 0;
    for(int i = 0; i < m; i++){
        if(!num[i].empty()){
            sort(num[i].begin(), num[i].end(), greater<int>());
            for(int k = 0; k < num[i].size(); k++){
                lev[k].push_back({num[i][k], i});
            }
        }
        lev[num[i].size()].push_back({-INF, i});
    }
    for(int i = 0; i < n + 1; i++){
        for(auto p : lev[i]){
            if(p.first + nsum[p.second] <= 0){
                sum -= nsum[p.second];
                nsum[p.second] = 0;
            }
            else{
                sum += p.first;
                nsum[p.second] += p.first;
            }
        }
        res = max(res, sum);
    }
    cout << res << endl;
}