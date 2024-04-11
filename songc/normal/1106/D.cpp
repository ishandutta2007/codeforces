#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> L[101010];
bool visit[101010];
priority_queue< int, vector<int>, greater<int> > PQ;

int main(){
    int u, v;
    scanf("%d %d", &N, &M);
    for (int i=1; i<=M; i++){
        scanf("%d %d", &u, &v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    PQ.push(1);
    visit[1] = true;
    while (!PQ.empty()){
        int T = PQ.top();
        PQ.pop();
        printf("%d ", T);
        for (int it : L[T]){
            if (visit[it]) continue;
            PQ.push(it);
            visit[it] = true;
        }
    }
    return 0;
}