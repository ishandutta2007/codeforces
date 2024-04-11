#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2005;
const int mod = (int)1e9 + 7;

int n,m,k;
int u[MAXN];

int find(int i){return u[i] == i ? i : u[i] = find(u[i]);}
bool same(int i, int j){return find(i) == find(j);}
void unite(int i, int j){int fi = find(i), fj = find(j); u[fi] = fj;}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) u[i] = i;
    for(int i = 0; i <= n-k; i++){
        for(int j = 0; j < k/2; j++){
            unite(i+j, i+(k-1-j));
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) cnt += (i == find(i));
    ll res = 1;
    while(cnt--) res = res*m%mod;
    cout << res;
}