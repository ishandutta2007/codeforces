#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 64;

int N;
char g[MAXN][MAXN];
vector<pair<int, int> > pieces;

bool ill[2*MAXN][2*MAXN];

bool read(int dx, int dy){
    return ill[dx+MAXN][dy+MAXN];
}

void mark(int dx, int dy){
    ill[dx+MAXN][dy+MAXN] = true;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            cin >> g[i][j];
            if(g[i][j] == 'o')
                pieces.emplace_back(i, j);
        }
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(g[i][j] == '.'){
                for(auto p : pieces){
                    mark(i - p.first, j - p.second);
                }
            }

    bool works = true;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(g[i][j] == 'x'){
                bool hit = false;
                for(auto p : pieces){
                    hit |= !read(i - p.first, j - p.second); 
                }
                works &= hit;
            }

    if(!works) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(int dx=-N+1; dx<=N-1; dx++){
            for(int dy=-N+1; dy<=N-1; dy++){
                if(dy == 0 && dx == 0) cout << "o";
                else if(read(dx, dy)) cout << ".";
                else cout << "x";
            }
            cout << "\n";
        }
    } 

    cout.flush();
    return 0;
}