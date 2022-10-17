#include <iostream>
#define hw (y-x+1)/2
using namespace std;

const int SEGW = 1<<17;
int N, Q, prd[SEGW+5];
int seg[2*SEGW+5][60]; // time

void upd(int i = -1, int v = -1, int loc = 1, int x = 0, int y = SEGW-1){
    if((v!=-1) && (x>i || y<i)) return;
    if(x == y){
        if(v!=-1) prd[x] = v;
        for(int e=0; e<60; e++)
            if(e % prd[x]) seg[loc][e] = 1;
            else seg[loc][e] = 2;
        return;
    }
    
    upd(i, v, 2*loc, x, x+hw-1);
    upd(i, v, 2*loc+1, x+hw, y);

    for(int e=0; e<60; e++){
        int fe = seg[2*loc][e];
        int se = seg[2*loc+1][(e+fe)%60];
        seg[loc][e] = fe + se;
    }
}

int que(int e, int l, int r, int loc = 1, int x = 0, int y = SEGW-1){
    if(r<x || l>y) return 0;
    if(l<=x && y<=r) return seg[loc][e%60];

    int fe = que(e, l, r, 2*loc, x, x+hw-1);
    int se = que(e+fe, l, r, 2*loc+1, x+hw, y);
    return fe+se;
}

int main(){
    cin >> N;
    for(int i=0; i<SEGW; i++) prd[i] = 6;
    for(int i=0; i<N; i++) cin >> prd[i];
    upd();

    cin >> Q;
    for(int i=0; i<Q; i++){
        char t; cin >> t;
        if(t == 'C'){
            int x, v; cin >> x >> v;
            upd(x-1, v);
        }
        else{
            int x, y;
            cin >> x >> y;
            cout << que(0, x-1, y-2) << "\n";
        }
    }
    
    cout.flush();
    return 0;
}