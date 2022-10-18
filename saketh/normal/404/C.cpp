#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 100005;

int N, K, d[MAXN], P;
queue<int> v[MAXN];
queue<pair<int, int> > q;
vector<pair<int, int> > res;

int main(){
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        scanf("%d", d+i);
        v[d[i]].push(i);
        if(d[i] == 0){
            q.push(make_pair(i, 0));
            P++;   
        }
    }

    if(P != 1){ printf("-1\n"); return 0; }
    while(!q.empty()){
        int loc = q.front().first;
        int dst = q.front().second;
        q.pop();

        int C = K;
        if(dst>0) C--;

        while(C>0 && !v[dst+1].empty()){
            res.emplace_back(loc, v[dst+1].front());
            P++, C--;
            q.push(make_pair(v[dst+1].front(), dst+1));
            v[dst+1].pop();
        }
    }

    if(P != N){ printf("-1\n"); return 0; }
    printf("%d\n", (int)res.size());
    for(auto p : res) printf("%d %d\n", p.first+1, p.second+1);
    return 0;
}