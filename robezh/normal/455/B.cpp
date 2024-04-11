#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

struct node{
    int nxt[30], val[30];
    node(){
        fill(nxt, nxt+30, -1);
        fill(val, val+30, 0);
    }
}nds[N];

int id = 1;
int n,k;
string str[N];

int dfs(int v, bool first){
    int res = !first;
    for(int i = 0; i < 26; i++){
        if(nds[v].nxt[i] != -1){
            if(first) res = max(res, dfs(nds[v].nxt[i], !first));
            else res = min(res, dfs(nds[v].nxt[i], !first));
        }
    }
    return res;

}

int dfsinv(int v, bool first){
    bool can_out = false;
    for(int i = 0; i < 26; i++) if(nds[v].nxt[i] != -1) can_out = true;
    if(!can_out) return first;

    int res = !first;
    for(int i = 0; i < 26; i++){
        if(nds[v].nxt[i] != -1){
            if(first) res = max(res, dfsinv(nds[v].nxt[i], !first));
            else res = min(res, dfsinv(nds[v].nxt[i], !first));
        }

    }
    return res;
}

int main(){
    scanf("%d%d", &n, &k);
    getchar();
    for(int i = 0; i < n; i++){
        getline(cin, str[i]);
        int cid = 0;
        for(char c : str[i]){
            if(nds[cid].nxt[c-'a'] == -1) nds[cid].nxt[c-'a'] = id++;
            nds[cid].val[c-'a'] ++;
            cid = nds[cid].nxt[c-'a'];
        }
        nds[cid].val[26] ++;
    }
    int d = dfs(0, true), dinv = dfsinv(0, true);

    //cout << d << " " << dinv << endl;
    //assert(d || dinv);
    if(dinv && d) return !printf("First");
    else if(!dinv && d) return !printf(k % 2 ? "First" : "Second");
    else return !printf("Second");
}