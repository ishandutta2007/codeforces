#include <bits/stdc++.h>
using namespace std;

const int N = 305;
typedef pair<int, int> P;

vector<int> S[N];
int n, d[N];
int cnt = 0;
vector<P> res;

void solve(int id){
    if(S[id].size() == 0){cnt++; return;}
    if(S[id].size() == 1){
        cnt = S[id][0] + 1;
        for(int i = 0; i < cnt; i++){
            for(int j = i+1; j < cnt; j++) res.emplace_back(i, j);
        }
        return ;
    }
    for(int i = 1; i < (int)S[id].size() - 1; i++){
        S[id+1].push_back(S[id][i] - S[id][0]);
    }
    solve(id+1);
    int sz = S[id].size();
    int nkcnt = cnt + S[id][sz-1] - S[id][sz-2], fncnt = nkcnt + S[id][0];
    for(int i = nkcnt; i < fncnt; i++){
        for(int j = 0; j < i; j++) res.emplace_back(i, j);
    }
    cnt = fncnt;
}

int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &d[i]);
        S[0].push_back(d[i]);
    }
    solve(0);
    printf("%d\n", res.size());
    for(auto p : res){
        printf("%d %d\n", p.first + 1, p.second + 1);
    }
}