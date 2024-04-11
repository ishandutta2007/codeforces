#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
LL ans;
LL BIT[202020];
int X[202020], Y[202020];
bool chk[202020];
vector<int> xcomp, ycomp;
vector<int> V[202020];
map<int,int> M;

void update(int t){
    while (t <= N+1){
        BIT[t]++;
        t += t & -t;
    }
}

LL read(int t){
    LL ret = 0;
    while (t){
        ret += BIT[t];
        t -= t & -t;
    }
    return ret;
}

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        xcomp.push_back(X[i]);
        ycomp.push_back(Y[i]);
    }
    sort(xcomp.begin(), xcomp.end());
    sort(ycomp.begin(), ycomp.end());
    xcomp.erase(unique(xcomp.begin(), xcomp.end()), xcomp.end());
    ycomp.erase(unique(ycomp.begin(), ycomp.end()), ycomp.end());
    for (int i=1; i<=N; i++) {
        V[i].push_back(0);
        V[i].push_back(N+1);
    }
    for (int i=1; i<=N; i++) V[N-(lower_bound(ycomp.begin(), ycomp.end(), Y[i])-ycomp.begin())].push_back(lower_bound(xcomp.begin(), xcomp.end(), X[i])-xcomp.begin()+1);
    for (int i=1; i<=N; i++) sort(V[i].begin(), V[i].end());
    for (int i=1; i<=N; i++){
        LL cnt = read(N+1);
        for (int j=1; j<(int)V[i].size()-1; j++) if (chk[V[i][j]]) cnt--;
        ans += cnt * (cnt+1) / 2;
        for (int j=0; j<(int)V[i].size()-1; j++){
            cnt = read(V[i][j+1]-1) - read(V[i][j]);
            ans -= cnt * (cnt+1) / 2;
        }
        for (int j=1; j<(int)V[i].size()-1; j++){
            if (!chk[V[i][j]]){
                update(V[i][j]);
                chk[V[i][j]] = true;
            }
        }
        for (int j=1; j<(int)V[i].size()-1; j++) ans += read(V[i][j]);
        for (int j=1; j<(int)V[i].size()-1; j++) ans += read(N+1) - read(V[i][j]-1);
        ans -= ((LL)V[i].size()-2) * (V[i].size()-1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}