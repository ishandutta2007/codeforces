#include <bits/stdc++.h>
using namespace std;

struct tup{
    int a,b,c;
    tup(){;}
    tup(int _a, int _b, int _c){a = _a, b = _b, c = _c;}
};

int n, k;
int num[5][55];
int zx, zy;
int nxtx[5][55], nxty[5][55];
vector<tup> res;

void prt(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
            cout << num[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool check_valid(){
    for(int i = 1; i <= 2; i++){
        for(int j = 0; j < n; j++) if(num[i][j] == 0){zx = i, zy = j;return true;}
    }
    for(int i = 0; i < n; i++) if(num[1][i] == num[0][i]){
            res.push_back(tup(num[1][i],0,i));
            zx = 1, zy = i;
            num[1][i] = 0;
            return true;
        }
    for(int i = 0; i < n; i++) if(num[2][i] == num[3][i]){
            res.push_back(tup(num[2][i],3,i));
            zx = 2, zy = i;
            num[2][i] = 0;
            return true;
        }
    return false;
}

void move_sig(int x, int y, int nx, int ny){
    if(num[x][y] != 0){
        res.push_back(tup(num[x][y], nx, ny));
        num[nx][ny] = num[x][y];
        num[x][y] = 0;
    }
}

void move(){
    int cx = zx, cy = zy;
    for(int i = 0; i < 2*n-1; i++){
        move_sig(nxtx[cx][cy], nxty[cx][cy], cx, cy);
        int nx = nxtx[cx][cy], ny = nxty[cx][cy];
        cx = nx, cy = ny;
    }
    for(int i = 1; i <= 2; i++) for(int j = 0; j < n; j++) if(num[i][j] == 0){
                zx = i, zy = j;
                return ;
            }
}

void psh(){
    for(int i = 0; i < n; i++) if(num[1][i] == num[0][i] && num[1][i] != 0){
            res.push_back(tup(num[1][i],0,i));
            num[1][i] = 0;
        }
    for(int i = 0; i < n; i++) if(num[2][i] == num[3][i] && num[2][i] != 0){
            res.push_back(tup(num[2][i],3,i));
            num[2][i] = 0;
        }
}

void set_nxt(){
    for(int i = 0; i < n-1; i++) nxtx[1][i] = 1, nxty[1][i] = i+1;
    nxtx[1][n-1] = 2, nxty[1][n-1] = n-1;
    for(int i = 1; i < n; i++) nxtx[2][i] = 2, nxty[2][i] = i-1;
    nxtx[2][0] = 1, nxty[2][0] = 0;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) cin >> num[i][j];
    }
    if(!check_valid()) return !printf("-1");

    set_nxt();
    //cout << "zxzy : " << zx << " " << zy << endl;
    for(int i = 0; i < 200; i++){
        psh();
        move();
        //prt();
    }
    printf("%d\n", res.size());
    for(auto t : res){
        printf("%d %d %d\n", t.a, t.b + 1, t.c + 1);
    }


}