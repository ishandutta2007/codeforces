#include<bits/stdc++.h>
using namespace std;
int x[300009], y[300009];
int pos[300009];
long long s[300009];
vector<pair<int,int> > v;
vector<int> V[300009];
long long SCORE(int i, int j){
    return min(x[i] + y[j], x[j] + y[i]);
}
main(){
    int n, m;
    long long S = 0;
    cin >> n>> m;
    for(int i = 1; i <= n; i++){
        scanf("%d %d",&x[i], &y[i]);
        v.push_back({x[i] - y[i], i});
        S += y[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
        pos[v[i].second] = i + 1,
        s[i + 1] = s[i] + v[i].first;
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);

    }
    for(int i = 1; i <= n; i++){
        int X = pos[i];
        long long score = (long long)(n - X) * (x[i] - y[i])
                        + s[X - 1] + S
                        + (long long)(n - 2) *y[i];
        for(int j = 0; j < V[i].size(); j++)
            score -= SCORE(i, V[i][j]);
        printf("%lld ", score);

    }
}