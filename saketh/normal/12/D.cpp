#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define INF 1<<30
using namespace std;

struct lady{
    int a, b, c;
    bool operator<(const lady &y) const{
        if(a != y.a) return a < y.a;
        if(b != y.b) return b > y.b;
        return c < y.c;
    }
} v[500005];

int N;
map<int, int> pf;

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int j=0; j<N; j++) cin >> v[j].a;
    for(int j=0; j<N; j++) cin >> v[j].b;
    for(int j=0; j<N; j++) cin >> v[j].c;

    sort(v, v+N);
    pf[INF] = -INF;
    pf[-INF] = INF;

    int ans = 0;
    for(int i=N-1; i>=0; i--){
        map<int, int>::iterator it = pf.upper_bound(v[i].b);
        if(it->second > v[i].c) ans++;
        else if(pf[v[i].b] < v[i].c){
            pf[v[i].b] = v[i].c;
            for(it = --pf.lower_bound(v[i].b); it->second < v[i].c;)
                pf.erase(it--);
        }
    }

    cout << ans << endl;
    return 0;
}