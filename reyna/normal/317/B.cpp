//In the name of God
#include <iostream>
#include <map>
#include <cstdio>
#include <cmath>
using namespace std;
const int Maxn = 1e6 + 9;
const int Maxv = 3015;
pair<int,int> Que[Maxn * 10];
int bg,ed;
bool arr_mark[Maxv][Maxv];
int arr_num[Maxv][Maxv];
inline int num(pair<int,int> p){
    int x = p.first,y = p.second;
    if(abs(x) >= Maxv/2-1 || abs(y) >= Maxv/2-1)
        return 0;
    return arr_num[x + Maxv/2][y + Maxv/2];
}
inline void ins(const int &x,const int &y){
    if(!arr_mark[x + Maxv/2][y + Maxv/2] && num(make_pair(x,y)) >= 4){
        arr_mark[x + Maxv/2][y + Maxv/2] = 1;
        Que[ed++] = make_pair(x,y);
        ed %= Maxn;
    }
}
int main(){
    int n;
    cin >> n;
    arr_num[Maxv/2][Maxv/2] = n;
    ins(0,0);
    while(bg != ed){
        int x = Que[bg].first,y = Que[bg++].second;
        bg %= Maxn;
        int cnt = arr_num[x + Maxv/2][y + Maxv/2]/4;
        arr_num[x + Maxv/2][y + Maxv/2] %= 4;
        arr_mark[x + Maxv/2][y + Maxv/2] = 0;
        for(int r = -1; r < 2;r++){
            for(int l = -1; l < 2;l++){
                if(abs(r + l) == 1){
                    int nx = r + x,ny = l + y;
                    arr_num[nx + Maxv/2][ny + Maxv/2] += cnt;
                    ins(nx,ny);
                }
            }
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",num(make_pair(x,y)));
    }
    return 0;
}