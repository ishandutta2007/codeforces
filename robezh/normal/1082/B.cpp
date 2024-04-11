#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n;
string str;
vector<P> V;
int cnt = 0;

int main(){
    cin >> n;
    cin >> str;
    for(char c : str){
        int x = (c == 'G' ? 0 : 1);
        cnt += (c == 'G');

        if(V.empty() || V.back().first != x) V.push_back({x, 1});
        else V.back().second++;
    }
    int res = 0;
    for(int i = 0; i < V.size(); i++){
        auto p = V[i];
        if(p.first == 1) continue;
        res = max(res, p.second);
        if(p.second != cnt) res = max(res, p.second + 1);
        if(i - 2 >= 0 && V[i-1].second == 1){
            res = max(res, min(cnt, V[i-2].second + p.second + 1));
        }
        if(i + 2 < V.size() && V[i+1].second == 1){
            res = max(res, min(cnt, V[i+2].second + p.second + 1));
        }
    }
    cout << res << endl;
}