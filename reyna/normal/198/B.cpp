#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

const int Maxn = 1e5+10;
bool isBad[Maxn][2];
bool vis[Maxn][2];
int dis[Maxn][2];
pii Que[2*Maxn];
pii Co[3];
int first,last;
int n,k;
int bfs(pii hi){
    Que[last] = hi;
    last++;
    while(first != last){
        int u = Que[first].x, wall = Que[first].y;
        first++;
        //cerr << u << " " << wall << endl;
        for(int i = 0; i < 3;i++){
            int l = Co[i].x, r = Co[i].y;
            if(u+l > n-1)
                return 1;
            if((u+l) >= 0  && !vis[u+l][abs(r-wall)] && !isBad[u+l][abs(r-wall)] && (u+l) >= dis[u][wall]+1){
                vis[u+l][abs(r-wall)] = true;
                dis[u+l][abs(r-wall)] = dis[u][wall]+1;
                Que[last] = make_pair(u+l,abs(r-wall));
                last++;
            }
        }
    }
    return 0;
}
int main(){
    cin >> n >> k;
    Co[0].x = 1;
    Co[0].y = 0;
    Co[1].x = -1;
    Co[1].y = 0;
    Co[2].x = k;
    Co[2].y = 1;
    string S,P;
    cin >> S >> P;
    for(int i = 0; i < n;i++){
        if(S[i] == 'X')
            isBad[i][0] = true;
    }
    for(int i = 0; i < n;i++){
        if(P[i] == 'X')
            isBad[i][1] = true;
    }
    if(bfs(make_pair(0,0)))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}