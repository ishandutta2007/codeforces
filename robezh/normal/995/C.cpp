#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n, tn;
double x[2*N], y[2*N];
bool good[2*N];
vector<int> G[2*N];
vector<int> quar[3];

int belong(double x, double y){
    double hyp = sqrt(x * x + y * y);
    if(x >= 0 && hyp < 2 * x) return 0;
    if(x <= 0 && hyp < 2 * (-x)) return 2;
    return 1;
}

int larger(){
    for(int i = 0; i < 3; i++) if(quar[i].size() > 1) return i;
    return -1;
}

int combine(int i, int j){
    int nxt = n++;

    good[i] = true;
    double res1 = sqrt((x[i]+x[j])*(x[i]+x[j])+(y[i]+y[j])*(y[i]+y[j]));
    double res2 = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    if(res2 < res1){
        x[nxt] = x[i]-x[j], y[nxt] = y[i]-y[j];
        good[j] = false;
    }
    else{
        x[nxt] = x[i]+x[j], y[nxt] = y[i]+y[j];
        good[j] = true;
    }
    G[nxt].push_back(i);
    G[nxt].push_back(j);
    return nxt;
}

void dfs(int v, bool rever){
    if(G[v].size() == 0){
        bool res = (rever ^ (!good[v]));
        good[v] = !res;
    }
    else{
        for(int nxt : G[v]){
            dfs(nxt, (rever ^ (!good[v])));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    tn = n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        quar[belong(x[i],y[i])].push_back(i);
    }

    while(true){
        int lar = larger();
        if(lar == -1) break;
        int now = combine(quar[lar][quar[lar].size()-1], quar[lar][quar[lar].size()-2]);
        quar[lar].pop_back();
        quar[lar].pop_back();
        quar[belong(x[now],y[now])].push_back(now);

    }
    int cnt = 0;
    vector<int> rest;
    for(int i = 0; i < 3; i++){
        if(quar[i].size() != 0) rest.push_back(quar[i][0]);
    }
    for(int i = 0; i < (1 << rest.size()); i++){
        double nx = 0, ny = 0;
        for(int j = 0; j < rest.size(); j++){
            if(i&(1<<j)) nx += x[rest[j]], ny += y[rest[j]], good[rest[j]] = true;
            else nx -= x[rest[j]], ny -= y[rest[j]], good[rest[j]] = false;
        }
        if(sqrt(nx*nx + ny*ny) < 1e6 + 1e5) break;
    }

    for(int i : rest){
        dfs(i, false);
    }

    for(int i = 0; i < tn; i++){
        cout << (good[i] ? "1" : "-1") << " ";
    }
//    double nx = 0, ny = 0;
//    for(int i = 0; i < tn; i++){
//        if(good[i]){nx += x[i], ny += y[i];}
//        else {nx -= x[i], ny -= y[i];}
//    }
    //cout << fixed << setprecision(10) << sqrt(nx * nx + ny * ny) << endl;



}