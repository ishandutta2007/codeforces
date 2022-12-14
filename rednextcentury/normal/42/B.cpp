#include<bits/stdc++.h>
using namespace std;
#define ll long long
int pos[100][100];
pair<int,int> getPos(){
    char x;
    int y;
    cin>>x>>y;
    int X = x-'a'+1;
    return {X,y};
}
bool safe(pair<int,int> w, pair<int,int> b){
    if (b.first<=0 || b.first>8 || b.second<=0 || b.second>8)return 0;
    if (b==w)return 0;
    if (abs(w.first-b.first)<=1 && abs(w.second-b.second)<=1)return 0;
    int x = b.first, y = b.second;
    while(x>=1){
        x--;
        if (w==make_pair(x,y))break;
        if (pos[x][y])return 0;
    }
    x = b.first, y = b.second;
    while(y>=1){
        y--;
        if (w==make_pair(x,y))break;
        if (pos[x][y])return 0;
    }
    x = b.first, y = b.second;
    while(y<=8){
        y++;
        if (w==make_pair(x,y))break;
        if (pos[x][y])return 0;
    }
    x = b.first, y = b.second;
    while(x<=8){
        x++;
        if (w==make_pair(x,y))break;
        if (pos[x][y])return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for (int i=0;i<2;i++){
        auto p = getPos();
        pos[p.first][p.second]=1;
    }
    auto white = getPos();
    auto black = getPos();
    bool curDanger = !safe(white, black);
    bool is=0;
    for (int x=-1;x<=1;x++){
        for (int j=-1;j<=1;j++){
            is=is||safe(white, {black.first+x,black.second+j});
        }
    }
    if (is || !curDanger)cout<<"OTHER"<<endl;
    else cout<<"CHECKMATE"<<endl;
}