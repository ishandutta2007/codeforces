#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int inf = (int)1E+9;

typedef long long int64;
typedef pair<int,int> pii;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define last(a) (int)a.size() - 1
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

const string task = "a";
const string inp = task + ".in";
const string outp = task + ".out";


int px[] = {1,0,-1,0};
int py[] = {0,1,0,-1};
char c[] = {'D','L','U','R'};

bool used[500][500];

void no(){
    puts("BUG");
    exit(0);
}

int main(){
    int x,y;
    x = y = 300;
    used[x][y] = 1;
    string s;
    cin >> s;
    forn(i,s.size()){
        int pos;
        forn(k,4)
            if (c[k] == s[i]) pos = k;
        x = x + px[pos];
        y = y + py[pos];
        int cnt = 0;
        if (used[x][y]) no();
        used[x][y] = 1;
        forn(k,4)
            if (used[x + px[k]][y + py[k]]) cnt++;
        if (cnt > 1) no();
    }
    puts("OK");
        
        
        

    return 0;
}