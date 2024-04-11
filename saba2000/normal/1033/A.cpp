#include<bits/stdc++.h>
using namespace std;
const int mx = 5e5 + 9;
int f[1009][1009];
    int a,b,c,d,e,F,n;
bool ch(int x, int y){
    if(x >=  1 && x <= n && y >= 1 && y <= n &&
       f[x][y] == 0){
            if(x-c == y-d) return 0;
            if(x+c == y+d) return 0;
            if(x == c) return 0;
            if(y == d) return 0;
            return 1;
       }
       return 0;
}
void dfs(int x, int y){
    f[x][y] =1;
   // cout<<x<<" "<<y<<endl;
    if(ch(x-1,y)) dfs(x-1,y);
    if(ch(x+1,y)) dfs(x+1,y);
    if(ch(x,y+1)) dfs(x,y+1);
    if(ch(x,y-1)) dfs(x,y-1);
     if(ch(x-1,y-1)) dfs(x-1,y-1);
    if(ch(x+1,y+1)) dfs(x+1,y+1);
    if(ch(x-1,y+1)) dfs(x-1,y+1);
    if(ch(x+1,y-1)) dfs(x+1,y-1);
}
main(){
    cin >> n;
    cin>>c>>d>>a>>b>>e>>F;
    dfs(a,b);
    if(f[e][F]){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}