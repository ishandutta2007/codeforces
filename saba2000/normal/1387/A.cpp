#include<bits/stdc++.h>
using namespace std;
int sg[100009], c[100009], ans[100009];
vector<pair<int,int> > v[100009];
int px, fl = 0;
vector<int> cur;
void dfs(int x){
    cur.push_back(x);
    for(auto e : v[x]){
        int y = e.first, l = e.second;
        int S = -sg[x], C = l - c[x];
        if(sg[y]){
            if(sg[y] == S && c[y] != C){
                cout << "NO" << endl;
                exit(0);
            }
            if(sg[y] != S){
                int P = c[y] - C;
                if(S == -1) P = -P;
                if(fl && P != px){
                    cout << "NO" << endl;
                    exit(0);
                }
                fl = 1; px = P;
            }
        }
        else {
            sg[y] = S;
            c[y] = C;
             dfs(y);
        }
    }
}
main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i = 1; i <= n; i++){
        if(sg[i] == 0){
            sg[i] = 1; c[i] = 0;
            cur.clear();
            px = 0; fl = 0;
            dfs(i);
            if(!fl){
                vector<int> w;
                for(int i : cur){
                    w.push_back(-sg[i] * c[i]);
                }
                sort(w.begin(), w.end());
                px = 2*w[w.size()/2];
            }
            for(int i : cur){
                ans[i] = sg[i] * px + 2 * c[i];
            }
        }
    }

    cout << "YES" << endl;
    for(int i = 1; i <= n; i++)
       printf("%.1f ", 0.5 * ans[i]);


}

/*
x+a1 x+
*/