#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <stack>
#include <cassert>
#include <list>
//#include <unordered_set>
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
void solve();

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    clock_t start = clock();
#else
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

#ifdef DEBUG
    //cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
    return 0;
}

bool used[1621][1621];
int m[1621][1621];
int c[1621][1621];
bool d[1621][1621];
int color = 1;



int w, h;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

int s = 0;


struct same{
    bool operator() (const pi& x, const pi& y) const {
        return abs(x.first - y.first) + abs(x.second - y.second) < 4;
    }
};

void bfs(int x, int y) {
    //cerr << "start" << ' ' << x << ' ' << y <<endl;
    queue<pi> q;
    q.push(pi(x, y));
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        //cerr << a << ' '<<  b << endl;
        if(abs(a - x) + abs(b - y) > 2)
            break;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            if(m[a + dx[i]][b + dy[i]] && !c[a + dx[i]][b + dy[i]]) {
                
                c[a + dx[i]][b + dy[i]] = color;
                q.push(pi(a + dx[i], b + dy[i]));
            }
        }
    }
}

void corner(int x, int y) {
    int cnt = 0;
    for(int i = x - 1; i <= x+ 1; ++i)
        for(int j = y - 1; j <= y + 1; ++j){
            cnt += m[i][j];
            
        }
    
    int cnt2 = 0;
    for(int i = x - 2; i <= x+ 2; ++i)
        for(int j = y - 2; j <= y + 2; ++j){
            cnt2 += m[i][j];
            
        }
    
    if(cnt <= 4 && cnt2<=9) {
        if(!c[x][y]) {
            d[x][y] = true;
            c[x][y] = color;
            bfs(x, y);
            ++s;
        }
        
        
    }
}


void dfs(int x, int y) {
    if(x < 5 || y < 5 || x > 6 + h || y > 6 + w)
        return;
    if(!m[x][y])
        return;
    if(used[x][y])
        return;
    used[x][y] = true;
    corner(x, y);
    
    for(int i = 0; i < 4; ++i)
        dfs(x + dx[i], y + dy[i]);
    
}

void solve() {
    cin >> h >> w;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            cin >> m[i + 5][j + 5];
            //cout << m[i][j];
        }
        //cout << endl;
    }
    
    
    vector<int> groups;
    
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j) {
            if(!used[5 + i][5 + j] && m[i + 5][j + 5]) {
                ++color;
                dfs(5 + i, 5 + j);
                groups.push_back(s);
                s = 0;
            }
        }
    }
    
    
    cout << groups.size() << endl;
    sort(all(groups));
    for(int i = 0; i < groups.size(); ++i)
        cout << groups[i] <<' ';
    /*
    for(int i = 0; i < h; ++i) {
        cout << endl;
        for(int j = 0; j < w; ++j) {
            cin >> m[i + 5][j + 5]; 
            if(d[i + 5][j + 5])
                cout<<2;
            else
                cout << m[i + 5][j + 5];
        }
        
    }*/

}