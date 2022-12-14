#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define mabs(x) ((x)<0?-(x):(x))

vector<string> ans;
char s[100]; int sx, sy, ex, ey;

string dir[8] = {"U", "RU", "R", "RD", "D", "LD", "L", "LU"};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int dis(int nx, int ny){
    return mabs(nx-ex) + mabs(ny-ey);
}

void find(int nx, int ny){
    if(dis(nx,ny)==0) return;
    int mn = 10000, mdir = 0;
    for(int i=0; i<8; i++){
        if(dis(nx+dx[i], ny+dy[i]) < mn){
            mn = dis(nx+dx[i], ny+dy[i]);
            mdir = i;
        }
    }
    ans.push_back(dir[mdir]);
    find(nx+dx[mdir], ny+dy[mdir]);
}

int main(){
    gets(s); sx = s[0]-'a'; sy = s[1] - '1';
    gets(s); ex = s[0]-'a'; ey = s[1] - '1';
    find(sx,sy);
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}