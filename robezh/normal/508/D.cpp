#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;

int n;
string str;
int in[128 * 128], out[128 * 128];
vector<int> G[128 * 128];
string res;

string get(int v){
    string res;
    res += (char)(v / 128);
    res += (char)(v % 128);
    return res;
}

void dfs(int v){
    //cout << "finding "  << (char)(v / 128) << (char)(v % 128) << endl;
    while(G[v].size()){
        int nxt = G[v].back(); G[v].pop_back();
        dfs(nxt);
    }
    res.push_back((char)(v % 128));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        int a = str[0] * 128 + str[1], b = str[1] * 128 + str[2];
        G[a].push_back(b);
        out[a] ++;
        in[b] ++;
    }
    int cnt = 0;
    int st = -1;
    for(int i = 0; i < 128 * 128; i++){
        if(abs(out[i] - in[i]) >= 2) return !printf("NO");
        if(out[i] - in[i] == 1){
            if(cnt == 0) st = i, cnt++;
            else return !printf("NO");
        }
    }

    if(st == -1){
        for(int i = 0; i < 128 * 128; i++){
            if(G[i].size()){st = i; break;}
        }
    }
    if(st == -1) return !printf("NO");
    dfs(st);

    res.push_back((char)(st / 128));
    reverse(res.begin(), res.end());
    if(res.length() != n+2) return !printf("NO");
    printf("YES\n");
    cout << res << endl;

}