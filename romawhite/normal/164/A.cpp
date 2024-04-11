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
vector<int> g[100005];
vector<int> g1[100005];
vector<int> a;
bool used1[100005];
bool used2[100005];
queue<int> q1;
queue<int> q2;
int n,m;
int main() {
    CLEAR(used1);
    CLEAR(used2);
    cin >> n >> m;
    FOR(i,0,n){
        int k;
        cin >> k;
        if (k==1){
            used1[i] = 1;
            q1.push(i);
        }
        if (k==2){
            used2[i] = 1;
            q2.push(i);
        }
        a.PB(k);
    }
    FOR(i,0,m){
        int k,l;
        cin >> k >> l;
        k--;l--;
        g[k].PB(l);
        g1[l].PB(k);
    }
    
    while (!q1.empty()) {
        int v = q1.front();
        q1.pop();
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (!used1[to]) {
                used1[to] = 1;
                q1.push (to);
            }
        }
    }

    while (!q2.empty()) {
        int v = q2.front();
        q2.pop();
        for (size_t i=0; i<g1[v].size(); ++i) {
            int to = g1[v][i];
            if (!used2[to]) {
                used2[to] = 1;
                if (a[to]!=1) 
                    q2.push (to);
            }
        } 
    }

    FOR(i,0,n)
        cout << (used1[i] &&  used2[i]) << endl;

    return 0;
}