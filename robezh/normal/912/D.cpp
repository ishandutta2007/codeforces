#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, P> Pk;


int n,m,r,k;
int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
priority_queue<Pk> pque;
ll sum = 0;
map<P, int> exi;

bool in_bound(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

ll expec(int x, int y){
    ll tx = min(min(m-r+1, r), min(y+1, m-y));
    ll ty = min(min(n-r+1, r), min(x+1, n-x));
    return tx * ty;
}

int main(){
    cin >> n >> m >> r >> k;
    int sx = n/2, sy = m/2;
    ll sexpe = expec(sx, sy);
    pque.push(Pk(sexpe, P(sx, sy)));
    exi[P(sx,sy)] = 1;
    //sum += sexpe;
    while(k){
        Pk pk = pque.top(); pque.pop();
        sum += pk.first;
        int ix = pk.second.first, iy = pk.second.second;
        //cout << "ix = " << ix << ", iy = " << iy << " added = " << pk.first << endl;
        for(int i = 0; i < 4; i++){
            int nx = ix+dx[i], ny = iy+dy[i];
            if(!in_bound(nx, ny)) continue;
            if(!exi.count(P(nx,ny))){
                pque.push(Pk(expec(nx,ny),P(nx,ny)));
                exi[P(nx,ny)] = 1;
            }
        }
        k--;
    }
    double res = (double)sum / ((ll)(m-r+1) * (n-r+1));
    cout << fixed << setprecision(10) << res;

}