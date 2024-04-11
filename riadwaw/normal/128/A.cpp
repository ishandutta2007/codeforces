#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;
void solve();

#define mp make_pair
#define pb push_back

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
string s[8];
int res [8][8][20];
int rec(int x,int y,int h){
    if(x<0)
        return false;
    if(y<0)
        return false;
    if(x>7)
        return false;
    if(y>7)
        return false;
    if(h==10)
        return true;
    if(res[x][y][h]!=-1)
        return res[x][y][h];
    if((x>=h && s[x-h][y]=='S') || (x>=h-1 && x-h+1<=7 && s[x-h+1][y]=='S'))
        return res[x][y][h] = false;
    res[x][y][h]=false;
    for(int i=-1;i<=1;++i)
        for(int j=-1;j<=1;++j){
            if(rec(x+i,y+j,h+1)){
                res[x][y][h]=1;
                return true;
            }
        }
    return res[x][y][h];
}
void solve() {
    memset(res,-1,sizeof(res));
    for(int i=0;i<8;++i){
        cin>>s[i];
    }

    if(rec(7,0,0))
        cout<<"WIN";
    else
        cout<<"LOSE";
}