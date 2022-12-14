//In the name of God
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int Maxn = 2016;
string mat[Maxn];
char ans[Maxn][Maxn];
int num[Maxn][Maxn];
vector<pair<int,int> > Que;
int n,m;
bool die = 0;
bool ch(int i,int j){
    if(i == -1 || j == -1 || i == n || j == m || ans[i][j] != '.')
        return 0;
    return 1;
}
int adj(int i,int j){
    int cnt = 0;
    for(int r = -1; r < 2;r++)
        for(int l = -1; l < 2;l++)
            if(abs(r+l) == 1 && ch(i+r,j+l))
                cnt++;
    return cnt;
}
void kill(int i,int j){
//  cerr << i << '*' << j << endl;
    for(int r = -1; r < 2;r++)
        for(int l = -1;l < 2;l++)
            if(abs(r+l) == 1 && ch(i+r,j+l)){
                num[i+r][j+l]--;
    //          cerr << i + r << '|' << j + l << endl;
                if(num[i+r][j+l] == 1){
                    Que.push_back(make_pair(i+r,j+l));
                }
            }
    return;
}
void Ans(int i,int j){
    bool k = 0;
    if(ch(i-1,j))
        ans[i][j] = 'v',ans[i-1][j] = '^',k = 1,kill(i-1,j);
    if(ch(i+1,j))
        ans[i][j] = '^',ans[i+1][j] = 'v',k = 1,kill(i+1,j);
    if(ch(i,j-1))
        ans[i][j] = '>',ans[i][j-1] = '<',k = 1,kill(i,j-1);
    if(ch(i,j+1))
        ans[i][j] = '<',ans[i][j+1] = '>',k = 1,kill(i,j+1);
    if(k == 0){
        die = 1;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n;i++)
        cin >> mat[i];
    for(int i = 0; i < n;i++)
        for(int j = 0; j < m;j++){
            ans[i][j] = mat[i][j];
        }
    for(int i = 0; i < n;i++)
        for(int j = 0; j < m;j++){
            if(ans[i][j] == '.'){
                num[i][j] = adj(i,j);
                if(num[i][j] == 0)
                    die = 1;
                if(num[i][j] == 1)
                    Que.push_back(make_pair(i,j));
            }
        }
    while(Que.size()){
        int x = Que[Que.size()-1].first,y = Que[Que.size()-1].second;
        Que.pop_back();
        if(ans[x][y] != '.')
            continue;
        if(num[x][y] == 0){
            die = 1;
            break;
        }
//      cerr << x << ' ' << y << endl;
        Ans(x,y);
        kill(x,y);
    }
//  cerr << num[1][1] << endl;
    
    for(int i = 0; i < n;i++)
        for(int j = 0; j < m;j++)
            if(ans[i][j] == '.')
                die = 1;
//              for(int i = 0; i < n;i++){
//      for(int j = 0; j < m;j++)
//          cerr << ans[i][j];
//      cerr << endl;
//  }
    if(die){
        cout << "Not unique" << endl;
        return 0;
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
            
            
}