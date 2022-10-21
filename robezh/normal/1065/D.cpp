#include <bits/stdc++.h>
using namespace std;

const int N = 12, INF = (int)1e9;

struct node{
    int type, num, x, y, trans;
    node(){};
    node(int _type, int _num, int _x, int _y, int _trans){type = _type, num = _num, x = _x, y = _y, trans = _trans;}
};

struct P{
    pair<int, int> pi;
    node nd;
    P(int first, int second, node _nd){
        pi.first = first, pi.second = second, nd = _nd;
    }
    bool operator < (const P &other) const{
        return pi > other.pi;
    }
};

int n;
int num[N][N], pt[N*N][2];
int dis[3][N*N][N][N], swa[3][N*N][N][N];
int dx[8] = {-1,-1,-2,-2,1,1,2,2}, dy[8] = {-2,2,-1,1,-2,2,-1,1};

bool in_bound(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

priority_queue<P> pque;
vector<node> get_next(node nd){
    vector<node> res;
    if(nd.type == 0){
        for(int d = 0; d < 8; d ++){
            int nx = nd.x + dx[d], ny = nd.y + dy[d];
            if(in_bound(nx, ny)){
                int cur_num = (nd.num + 1 == num[nx][ny] ? nd.num + 1 : nd.num);
                res.push_back(node(nd.type, cur_num, nx, ny, 0));
            }
        }
    }
    else if(nd.type == 1){
        for(int i = nd.x - min(nd.x, nd.y), j = nd.y - min(nd.x, nd.y); i < n && j < n; i++, j++){
            int cur_num = (nd.num + 1 == num[i][j] ? nd.num + 1 : nd.num);
            res.push_back(node(nd.type, cur_num, i, j, 0));
        }
        for(int i = nd.x - min(nd.x, n-1-nd.y), j = nd.y + min(nd.x, n-1-nd.y); i < n && j >= 0; i++, j--){
            int cur_num = (nd.num + 1 == num[i][j] ? nd.num + 1 : nd.num);
            res.push_back(node(nd.type, cur_num, i, j, 0));
        }
    }
    else{
        for(int i = 0, j = nd.y; i < n; i++){
            int cur_num = (nd.num + 1 == num[i][j] ? nd.num + 1 : nd.num);
            res.push_back(node(nd.type, cur_num, i, j, 0));
        }
        for(int i = nd.x, j = 0; j < n; j++){
            int cur_num = (nd.num + 1 == num[i][j] ? nd.num + 1 : nd.num);
            res.push_back(node(nd.type, cur_num, i, j, 0));
        }
    }
    for(int t = 0; t < 3; t++){
        if(t != nd.type) res.push_back(node(t, nd.num, nd.x, nd.y, 1));
    }
    return res;
}

void print(node nd){
    cout << nd.type << " " << nd.num << " " << nd.x << " " << nd.y << endl;
}

void update(node nd, int cur_val, int cur_swa){
    if(dis[nd.type][nd.num][nd.x][nd.y] > cur_val + 1){
        dis[nd.type][nd.num][nd.x][nd.y] = cur_val + 1;
        swa[nd.type][nd.num][nd.x][nd.y] = cur_swa + nd.trans;
        pque.push(P(cur_val + 1, cur_swa + nd.trans, node(nd.type, nd.num, nd.x, nd.y, 0)));
    }
    else if(dis[nd.type][nd.num][nd.x][nd.y] == cur_val + 1 && swa[nd.type][nd.num][nd.x][nd.y] > cur_swa + nd.trans){
        swa[nd.type][nd.num][nd.x][nd.y] = cur_swa + nd.trans;
        pque.push(P(cur_val + 1, cur_swa + nd.trans, node(nd.type, nd.num, nd.x, nd.y, 0)));
    }
}

int main(){
    memset(dis, 0x3f, sizeof(dis));
    memset(dis, 0x3f, sizeof(swa));
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num[i][j];
            pt[num[i][j]][0] = i, pt[num[i][j]][1] = j;
        }
    }
    for(int i = 0; i < 3; i++){
        dis[i][1][pt[1][0]][pt[1][1]] = 0;
        swa[i][1][pt[1][0]][pt[1][1]] = 0;
        pque.push(P(0, 0, node(i, 1, pt[1][0], pt[1][1], 0)));
    }

    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        auto pi = p.pi;
        node nd = p.nd;
        if(nd.num == n * n) continue;
        int cur_val = dis[nd.type][nd.num][nd.x][nd.y];
        int cur_swa = swa[nd.type][nd.num][nd.x][nd.y];
        if((pi.first == cur_val && pi.second > cur_swa) || pi.first > cur_val) continue;
        auto next_list = get_next(nd);
        for(node nxt : next_list){
            update(nxt, cur_val, cur_swa);
        }
    }
    int res = INF, min_swap = INF;
    for(int i = 0; i < 3; i++){
        if(res > dis[i][n*n][pt[n*n][0]][pt[n*n][1]]){
            res = dis[i][n*n][pt[n*n][0]][pt[n*n][1]];
            min_swap = swa[i][n*n][pt[n*n][0]][pt[n*n][1]];
        }
        else if(res == dis[i][n*n][pt[n*n][0]][pt[n*n][1]]){
            min_swap = min(min_swap, swa[i][n*n][pt[n*n][0]][pt[n*n][1]]);
        }
    }
    cout << res << " " << min_swap << endl;

}