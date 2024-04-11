#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k;
ll dist[305][305];
int a,b,c;

int main(){

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> dist[i][j];
        }
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = min(dist[a][b], (ll)c);
        dist[b][a] = min(dist[b][a], (ll)c);

        ll res = 0;
        for(int p = 0; p < n; p++){
            for(int q = 0; q < n; q++){
                dist[p][q] = min(dist[p][q], dist[p][a] + dist[a][b] + dist[b][q]);
                dist[p][q] = min(dist[p][q], dist[p][b] + dist[b][a] + dist[a][q]);
                res += dist[p][q];
            }
        }
        printf("%I64d ", res/2);
    }
}