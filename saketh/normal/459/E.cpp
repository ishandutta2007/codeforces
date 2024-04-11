#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
    int a, b, w;
    bool operator< (const edge e) const { return w < e.w; }
};

int N, M;
edge e[300005];
int len[300005], plen[300005];
int last[300005], plast[300005];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0; i<M; i++)
        cin >> e[i].a >> e[i].b >> e[i].w;
    sort(e, e+M);

    for(int i=0; i<M; i++){
        if(e[i].w > last[e[i].a] && (len[e[i].a] + 1) > len[e[i].b]){
            plen[e[i].b] = len[e[i].b];
            len[e[i].b] = len[e[i].a] + 1;
            plast[e[i].b] = last[e[i].b];
            last[e[i].b] = e[i].w;
        }
        if(e[i].w > plast[e[i].a] && (plen[e[i].a] + 1) > len[e[i].b]){
            plen[e[i].b] = len[e[i].b];
            len[e[i].b] = plen[e[i].a] + 1;
            plast[e[i].b] = last[e[i].b];
            last[e[i].b] = e[i].w;
        }
    }

    int ans = 0;
    for(int i=1; i<=N; i++)
        ans = max(ans, len[i]);
    cout << ans << endl;
    return 0;
}