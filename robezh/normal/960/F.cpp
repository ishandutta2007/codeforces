#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int n,m,a,b,w;
// it -> first is the ending node, while it->second is the length
map<int, int> M[100500];

int main(){
    scanf("%d%d",&n, &m);
    for(int i = 1; i <= n; i++) M[i][-1] = 0;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &w);
        auto it = M[a].lower_bound(w);
        if(it == M[a].begin()) continue;
        it--;

        int oldlen = it -> second;
        int newlen = oldlen + 1;

        if(M[b].count(w)){M[b][w] = min(M[b][w], oldlen+1);}
        else M[b][w] = oldlen+1;

        it = M[b].find(w);
        if(it != M[b].begin()) {
            it--;
            if (it->second >= newlen){
                M[b].erase(w);
                continue;
            }
        }

        it = M[b].find(w);
        it++;
        while(it != M[b].end()){
            if(it->second > newlen) break;
            auto oldit = it;
            it++;
            M[b].erase(oldit);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        //cout << "i : " << i << endl;
        for(auto p : M[i]){
            //cout << p.first << " " << p.second << endl;
            res = max(res, p.second);
        }
    }
    cout << res;

}