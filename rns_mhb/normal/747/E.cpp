#include<bits/stdc++.h>
using namespace std;

#define N 2000200

string s[N];
int a[N];
vector <string> v[N];

char sos[N];
int cnt, cur, depth;

void run(int dep, int gas){
    if(gas == 0) return;
    depth = max(depth, dep);
    for(int step = 1; step <= gas && cur < cnt; step ++){
        v[dep].push_back(s[cur]);
        int tmp = a[cur]; cur ++;
        run(dep + 1, tmp);
    }
}

void print(string ss){
    int len = ss.size();
    for(int i = 0; i < len; i ++) printf("%c", ss[i]);
}

int main(){
  //  freopen("a.in", "r", stdin);
    gets(sos);
    cur = 0;
    cnt = 0;
    depth = 0;
    for(char *token = strtok(sos, " ,"); token != NULL; token = strtok(NULL, " ,")){
        cur ++;
        if(cur & 1){ s[cnt] = token; }
        else{ a[cnt] = atoi(token); cnt ++; }
    }
    cur = 0; run(1, N);
    cout << depth << endl;
    for(int i = 1; i <= depth; i ++){
        for(int j = 0; j < v[i].size(); j ++){
            if(j) printf(" ");
            print(v[i][j]);
        }puts("");
    }
}