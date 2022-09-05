#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
#include <stack>
#include <time.h>

using namespace std;
 
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
#define SZ(a) (int)(a).size()
 
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
 
const long double pi=acos(-1.0);
const int INF=1000000000;

string s[107];
int n,m,k;

pair<int,int> junc[27];

int d[107][107][30];
pair<int,int> p[107][107][30];

int ok(int x,int y){
    if (x < 0 || x >= n || y < 0 || y >= m) return -1;
    if (s[x][y] == '#') return -1;
    if (s[x][y] >= 'a' && s[x][y] <= 'z') return 1;
    return int(s[x][y] - '0');
}

bool j(int x,int y){
    return (s[x][y] >='a' && s[x][y] <='z');
}

int main() {
    cin >> n >> m >> k;
    FOR(i,0,n)
        cin >> s[i];

    FOR(i,0,26)
        junc[i] = MP(-1,-1);

    FOR(i,0,n)
        FOR(j,0,m)
            if (s[i][j] >= 'a' && s[i][j] <= 'z')
                junc[s[i][j] - 'a'] = MP(i,j);

    int Sx,Sy,Ex,Ey;
    string S;
    cin >> Sx >> Sy >> S >> Ex >> Ey;
    Sx--;
    Sy--;
    Ex--;
    Ey--;
    junc[26] = MP(Ex,Ey);

    FOR(i,0,107)
        FOR(j,0,107)
            FOR(t,0,30)
                d[i][j][t] = INF;
 
    FOR(i,0,27)
        if (junc[i] != MP(-1,-1)){

            d[junc[i].first][junc[i].second][i] = 0;
            priority_queue < pair<int,pair<int,int> > > q;
            q.push (make_pair (0, MP(junc[i].first , junc[i].second)));
            while (!q.empty()) {
                int vx = q.top().second.first,  cur_d = -q.top().first;
                int vy = q.top().second.second;
                q.pop();
                if (cur_d > d[vx][vy][i])  continue;

                if (ok(vx - 1,vy) != -1){
                    int len = ok(vx,vy);
                    if (d[vx][vy][i] + len < d[vx - 1][vy][i]) {
                        d[vx - 1][vy][i] = d[vx][vy][i] + len;
                        p[vx - 1][vy][i] = MP(vx,vy);
                        if (!j(vx - 1,vy))
                            q.push (make_pair (-d[vx - 1][vy][i], MP(vx - 1 , vy)));
                    }
                }

                if (ok(vx + 1,vy) != -1){
                    int len = ok(vx,vy);
                    if (d[vx][vy][i] + len < d[vx + 1][vy][i]) {
                        d[vx + 1][vy][i] = d[vx][vy][i] + len;
                        p[vx + 1][vy][i] = MP(vx,vy);
                        if (!j(vx + 1,vy))
                        q.push (make_pair (-d[vx + 1][vy][i], MP(vx + 1 , vy)));
                    }
                }

                if (ok(vx ,vy - 1) != -1){
                    int len = ok(vx,vy);
                    if (d[vx][vy][i] + len < d[vx][vy - 1][i]) {
                        d[vx][vy - 1][i] = d[vx][vy][i] + len;
                        p[vx][vy - 1][i] = MP(vx,vy);
                        if (!j(vx,vy - 1))
                        q.push (make_pair (-d[vx][vy - 1][i], MP(vx , vy - 1)));
                    }
                }

                if (ok(vx,vy + 1) != -1){
                    int len = ok(vx,vy);
                    if (d[vx][vy][i] + len < d[vx][vy + 1][i]) {
                        d[vx][vy + 1][i] = d[vx][vy][i] + len;
                        p[vx][vy + 1][i] = MP(vx,vy);
                        if (!j(vx,vy + 1))
                        q.push (make_pair (-d[vx][vy + 1][i], MP(vx , vy + 1)));
                    }
                }
            }

        }

    int X = Sx;
    int Y = Sy;
    int t = 0;

    S += ('a' + 26);
    FOR(i,0,S.size()){
        while (MP(X,Y) != junc[S[i] - 'a']){
            if (ok(X,Y) + t > k){
                cout << X + 1 << ' ' << Y + 1 << endl;
                return 0;
            }
            t += ok(X,Y);
            //cout << X << ' ' << Y << ' ' << t << endl;
            int XX = X, YY = Y;
            X = p[XX][YY][S[i] - 'a'].first;
            Y = p[XX][YY][S[i] - 'a'].second;
        }
    }

    cout << X + 1 << ' ' << Y + 1 << endl;

    return 0;
}