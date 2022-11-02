#include <bits/stdc++.h>
using namespace std;

#define L 1031
#define M 300001

char s[L], ss[L];

map<string, int> mp;
map<int, int> vis[M], bin;
vector<int> v[M], w[M];
int tot = 0;

string ans[M];

int find(string A) {
    if(mp[A]) return mp[A];

    mp[A] = ++tot;
    ans[tot] = A;
    return tot;
}

int sea(string A) {
    if(mp[A]) return mp[A];
    return mp[A] = ++tot;
}

string change(int x) {
    string B;
    while(x) {
        B += '0' + x % 10;
        x /= 10;
    }
    reverse(B.begin(), B.end());
    B += '?';
    return B;
}

int main() {
    ///freopen("c.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%s\n", s);
        strcpy(ss, s + 7);
        int j = 0;
        string A;
        for(;j < strlen(ss);j++) {
           if(ss[j] == '/') break;
           A += ss[j];
        }
        string B;
        for(;j < strlen(ss); j++) B += ss[j];
        B+='A';
        if(!B.size()) {
            int x = find(A);
            bin[x] = 1;
            continue;
        }
        int x = find(A);
        int y = find(B);
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        v[x].push_back(y);
    }
    mp.clear();
    int gas = tot;
    tot = 0;

    for(int i = 1; i <= gas; i ++) if(v[i].size()) {
        sort(v[i].begin(), v[i].end());
        string A;
        for(int j = 0; j < v[i].size(); j ++) A += change(v[i][j]);
        //if(bin[i]) A += change(9999999);
        int x = sea(A);
        w[x].push_back(i);
    }

    int cnt = 0;

    for(int i = 1; i <= tot; i ++) if(w[i].size() >= 2) {
        cnt ++;
    }

    printf("%d\n", cnt);
    for(int i = 1; i <= tot; i ++) if(w[i].size() >= 2){
        for(int j = 0; j < w[i].size(); j ++) {
            int x = w[i][j];
            if(j) printf(" ");
            printf("http://");
            cout<<ans[x];
        }
        puts("");
    }
}