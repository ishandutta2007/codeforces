#include<iostream>
#include<algorithm>
#include<set>
#include<string>
using namespace std;

int N, M, K, F, S;
int SX, SY;
set<pair<int, int> > fil;
bool maze[505][505];
string t;

void dfs(int r, int c){
    if(fil.size() == S-K) return;
    if(r<0 || r>=N || c<0 || c>=M) return;
    if(maze[r][c]) return;
    if(fil.count(make_pair(r, c))) return;
    
    fil.insert(make_pair(r, c));
    dfs(r+1, c);
    dfs(r-1, c);
    dfs(r, c+1);
    dfs(r, c-1);
}

int main(){
    cin >> N >> M >> K;
    
    S = N*M;
    
    for(int r=0; r<N; r++){
        cin >> t;
        for(int c=0; c<M; c++){
            bool block = t[c]=='#';
            if(!block){
                SX = r;
                SY = c;
            }
            else S--;
            maze[r][c] = block;
        }
    }
    
    dfs(SX, SY);
    
    for(int r=0; r<N; r++){
        for(int c=0; c<M; c++){
            if(maze[r][c]) cout << "#";
            else if(fil.count(make_pair(r, c))) cout << ".";
            else cout << "X";
        }
        cout << endl;
    }
    
    return 0;
}