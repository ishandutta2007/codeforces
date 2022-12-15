#include <bits/stdc++.h>

using namespace std;

vector<array<int, 2>> nxt[2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            nxt[(i + j) & 1].push_back({i, j});

    while(!nxt[0].empty() || !nxt[1].empty()){
        int a;
        cin >> a;

        if(nxt[0].empty()){
            cout << ((a == 2) ? 3 : 2) << " " << nxt[1].back()[0] << " " << nxt[1].back()[1] << "\n";
            cout.flush(); 
            nxt[1].pop_back();
        }
        else if(nxt[1].empty()){
            cout << ((a == 1) ? 3 : 1) << " " << nxt[0].back()[0] << " " << nxt[0].back()[1] << "\n";
            cout.flush(); 
            nxt[0].pop_back();
        }
        else{
            if(a == 2){
                cout << 1 << " " << nxt[0].back()[0] << " " << nxt[0].back()[1] << "\n";
                cout.flush();
                nxt[0].pop_back();
            }
            else{
                cout << 2 << " " << nxt[1].back()[0] << " " << nxt[1].back()[1] << "\n";
                cout.flush();
                nxt[1].pop_back();
            }
        }
    }
}