#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=2000000000;
const int mod=1000000007;
const int N = 10000005;
string s[1005];
int n,m;
bool f(int v,int to){
    //cout << s[v] << ' ' << s[to] << endl;
    FOR(i,0,m)
        if (s[v][i]=='#' && s[to][i]=='#')
            return 1;
    return 0;
}

int main() {
    cin >> n >> m;
    FOR(i,0,n){
        cin >> s[i];
    }
    vector<int> g[1005];
    queue<int> q;
    q.push (n-1);
    vector<int>used;
    FOR(i,0,n-1)
        used.PB(i);
    vector<int> d (n), p (n);
    p[n-1] = -1;
    while (!q.empty()) {
        int v = q.front();
        //cout << v << endl;
        q.pop();
        for (size_t i=0; i<used.size(); ++i) {
            int to = used[i];
            if (f(v,to)){
                for(vector<int>::iterator it=used.begin(); it!=used.end(); ++it)
                    if (*it == to){
                        used.erase(it);
                        break;
                    }
                q.push (to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    if (d[0] == 0) cout << -1;
    else cout << 2*d[0];
    return 0;
}