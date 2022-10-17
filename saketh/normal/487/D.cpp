#include <iostream>
using namespace std;

#define SIZE 17

int N, M, Q;
char grid[100005][16];
pair<int, int> seg[2<<SIZE][16];

void calc_row(int loc, int l){
    for(int i=0; i<M; i++)
        if(grid[l][i] == '^') seg[loc][i] = make_pair(l-1, i);
        else if(grid[l][i] == '<'){
            if(i == 0) seg[loc][i] = make_pair(l, -1);
            else if(grid[l][i-1] == '>') seg[loc][i] = make_pair(l, -2);
            else seg[loc][i] = seg[loc][i-1];
        }       

    for(int i=M-1; i>=0; i--){
        if(grid[l][i] == '>'){
            if(i == M-1) seg[loc][i] = make_pair(l, M);
            else seg[loc][i] = seg[loc][i+1];
        }
    }
}

void update(int row, int loc = 1, int l = 0, int h = (1<<SIZE)-1){
    if((row < l) || (row > h)) return;
    
    if(l == h){
        calc_row(loc, l);
        return;
    }
    else{
        int w = (h - l + 1)/2;
        update(row, 2*loc, l, l+w-1);
        update(row, 2*loc+1, l+w, h);

        for(int i=0; i<M; i++){
            pair<int, int> bot = seg[2*loc+1][i];
            if(bot.first > (l+w-1)) seg[loc][i] = bot;
            else seg[loc][i] = seg[2*loc][bot.second];
        }
    }
}

pair<int, int> query(int r, int c, int loc = 1, int l = 0, int h = (1<<SIZE)-1){
    if(l == h) return seg[loc][c];

    int w = (h - l + 1)/2;
    if(r <= (l+w-1)) return query(r, c, 2*loc, l, l+w-1);

    pair<int, int> bot = query(r, c, 2*loc+1, l+w, h);
    if(bot.first > (l+w-1)) return bot;
    return seg[2*loc][bot.second];
}

int main(){
    for(int i=0; i<(2<<SIZE); i++)
        for(int j=0; j<16; j++)
            seg[i][j] = make_pair(-1, j);

    cin >> N >> M >> Q;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> grid[i][j];

    for(int i=0; i<N; i++)
        update(i);

    for(int i=0; i<Q; i++){
        char c; int x, y; char n;
        cin >> c;
        if(c == 'A'){
            cin >> x >> y; x--; y--;
            pair<int, int> res = query(x, y);
            if(res.second == -2) cout << "-1 -1\n";
            else cout << res.first+1 << " " << res.second+1 << "\n";

        }
        else{
            cin >> x >> y >> n; x--; y--;
            grid[x][y] = n;
            update(x);
        }
       
    }
    cout.flush();
    return 0;
}