#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1<<16;

int N;
int dg[MAXN + 5];
int xr[MAXN + 5];

queue<int> leafs;
vector<pair<int, int> > ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> dg[i] >> xr[i];
        if(dg[i] == 1) leafs.push(i);
    }
    
    while(!leafs.empty()){
        int l = leafs.front(); leafs.pop();
        if(dg[l] != 1) continue;
        ans.emplace_back(l, xr[l]);

        xr[xr[l]] ^= l;
        if(--dg[xr[l]] == 1) leafs.push(xr[l]);
    }

    cout << ans.size() << "\n";
    for(auto p : ans) cout << p.first << " " << p.second << "\n";
    return 0;
}