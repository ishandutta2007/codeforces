#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#define hw (y-x+1)/2
using namespace std;

const int MAXN = 100005;
int N, M, K, Q;

struct query{
    int i, c1, c2, r1, r2;
    bool operator<(const query r) const{
        return c1 < r.c1;
    }
};

struct rook{
    int x, y;
    bool operator<(const rook q) const{
        return y < q.y;
    }
};

const int SEGW = 1<<17;
queue<int> row[SEGW+5];
int seg[2 * SEGW + 5];

int build_tree(int loc = 1, int x = 0, int y = SEGW-1){
    if(x==y) return seg[loc] = row[x].front();
    return seg[loc] = max(build_tree(2*loc, x, x+hw-1),
                          build_tree(2*loc+1, x+hw, y));
}

void setup(vector<rook> & rooks){
    for(int i=0; i<SEGW; i++)
        while(!row[i].empty())
            row[i].pop();
    memset(seg, 0, sizeof(seg));
    for(rook r : rooks)
        row[r.x].push(r.y);
    for(int i=0; i<SEGW; i++)
        row[i].push(MAXN+5);
    build_tree();
}

int pop_rook(rook r, int loc = 1, int x = 0, int y = SEGW-1){
    if(r.x < x || r.x > y) return seg[loc];
    if(x == y){
        row[x].pop();
        return seg[loc] = row[x].front();
    } 
    return seg[loc] = max(pop_rook(r, 2*loc, x, x+hw-1),
                          pop_rook(r, 2*loc+1, x+hw, y));
}

int find_max(int c1, int c2, int loc = 1, int x = 0, int y = SEGW-1){
    if(c1 > y || c2 < x) return -1;
    if(c1 <= x && y <= c2) return seg[loc];
    return max(find_max(c1, c2, 2*loc, x, x+hw-1),
               find_max(c1, c2, 2*loc+1, x+hw, y));
}

void solve(vector<rook> &rooks, vector<query> &queries, vector<bool> &ans){
    sort(queries.begin(), queries.end());
    sort(rooks.begin(), rooks.end());
    setup(rooks);

    int pop = 0;
    for(query qr : queries){
        while(pop < rooks.size() && rooks[pop].y < qr.c1){
            pop_rook(rooks[pop]);
            pop++;
        }

        int rm = find_max(qr.r1, qr.r2);
        ans[qr.i] = rm > qr.c2;
    }
}

vector<rook> R, R2;
vector<query> QU, QU2;
vector<bool> A, B;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K >> Q;
    for(int i=0; i<K; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        R.push_back({x, y});
        R2.push_back({y, x});
    }

    for(int i=0; i<Q; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--; 
        
        QU.push_back({i, c1, c2, r1, r2});
        QU2.push_back({i, r1, r2, c1, c2});
    }
    
    A.resize(Q);
    swap(N, M);
    B.resize(Q);
    
    solve(R, QU, A);
    solve(R2, QU2, B);

    for(int i=0; i<Q; i++){
        bool res = !(A[i] && B[i]);
        cout << ( res ? "YES" : "NO") << "\n";
    } 
}