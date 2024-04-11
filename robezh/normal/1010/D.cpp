#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500;

int n;
string s[N];
int op1[N], op2[N];
bool val[N];
int las[N];
int res[N];

bool get(string ok, bool o1, bool o2){
    if(ok == "AND") return o1 & o2;
    if(ok == "XOR") return o1 ^ o2;
    if(ok == "OR") return o1 | o2;
    if(ok == "NOT") return !o1;
}

void dfs(int v){
    if(s[v] == "IN")  return;
    if(s[v] == "AND" || s[v] == "XOR" || s[v] == "OR") dfs(op1[v]), dfs(op2[v]);
    else dfs(op1[v]);

    if(s[v] == "AND") val[v] = val[op1[v]] & val[op2[v]];
    if(s[v] == "XOR") val[v] = val[op1[v]] ^ val[op2[v]];
    if(s[v] == "OR") val[v] = val[op1[v]] | val[op2[v]];
    if(s[v] == "NOT") val[v] = !val[op1[v]];

}

void dfs2(int v){
    if(s[v] == "IN") res[v] = (val[v] ? las[v] % 2 : las[v] / 2);
    else if(s[v] == "NOT"){
        las[op1[v]] = las[v] % 2 * 2 + las[v] / 2;
        dfs2(op1[v]);
    }
    else{
        bool res0 = get(s[v], false, val[op2[v]]);
        bool res1 = get(s[v], true, val[op2[v]]);
        res0 = (res0 ? las[v] / 2 : las[v] % 2);
        res1 = (res1 ? las[v] / 2 : las[v] % 2);
        las[op1[v]] = res0 + (res1 ? 1 : 0) * 2;
        res0 = get(s[v], false, val[op1[v]]);
        res1 = get(s[v], true, val[op1[v]]);
        res0 = (res0 ? las[v] / 2 : las[v] % 2);
        res1 = (res1 ? las[v] / 2 : las[v] % 2);
        las[op2[v]] = res0 + res1 * 2;
        dfs2(op1[v]);
        dfs2(op2[v]);
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        if(s[i] == "AND" || s[i] == "XOR" || s[i] == "OR") cin >> op1[i] >> op2[i];
        else if(s[i] == "IN") cin >> val[i];
        else cin >> op1[i];
    }
    dfs(1);
    las[1] = 2;
    dfs2(1);
//    for(int i = 1; i <= n; i++) printf("%d: %d\n",i , las[i]);
//    for(int i = 1; i <=n ; i++) printf("%d val = %d\n", i , val[i]);
    for(int i = 1; i <= n; i++) if(s[i] == "IN") printf("%d", res[i]);

}