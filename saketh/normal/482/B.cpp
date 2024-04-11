#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct event{
    bool typ; // 0 = begin, 1 = end
    int l, r, q;
};

int loc(const event &e){
    return e.typ?e.r:e.l;
}

bool operator <(const event &x, const event &y){
    int xl = loc(x);
    int yl = loc(y);
    if(xl != yl) return xl < yl;
    return x.typ < y.typ;
}

int N, M;
vector<int> ans;
event ev[200005];
int run[32], req[32];

bool rem(int l, int r, int q){
    for(int i=0; i<30; i++){
        if((q>>i)&1){
            req[i]--;
        }
        else if(run[i] != -1 && run[i] <= l){
            return false;
        }
    }
    return true;
}

void ins(int l, int r, int q){
    for(int i=0; i<30; i++){
        if((q>>i)&1){
             req[i]++;
             if(run[i] == -1)
                 run[i] = l;
        }
    }
}

void clean(){
    for(int i=0; i<30; i++)
        if(!req[i])
            run[i] = -1;
}

int calc(){
    int ret = 0;
    for(int i=0; i<30; i++)
        if(req[i])
            ret |= 1<<i;
    return ret;
}

bool handle(){
    for(int i=0; i<30; i++)
        run[i] = -1;

    int i = 0;
    for(int v=0; v<N; v++){
        for(;i < 2*M && (loc(ev[i]) == v) && (ev[i].typ == 0); i++)
            ins(ev[i].l, ev[i].r, ev[i].q);

        clean();
        ans.push_back(calc());

        for(;i < 2*M && (loc(ev[i]) == v) && (ev[i].typ == 1); i++)
            if(!rem(ev[i].l, ev[i].r, ev[i].q))
                return false;
    }

    return true;
}

void assign(int i, int l, int r, int q){
    ev[i].l = l;
    ev[i].r = r;
    ev[i].q = q;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int l, r, q;
        cin >> l >> r >> q;
        l--;
        r--;

        ev[2*i].typ = 0;
        assign(2*i, l, r, q);

        ev[2*i+1].typ = 1;
        assign(2*i+1, l, r, q);
    }

    sort(ev, ev + 2 * M);
    
    if(handle()){
        cout << "YES" << endl;
        for(int i=0; i<N; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    else cout << "NO" << endl;
    return 0;
}