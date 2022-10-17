#include <iostream>
#include <algorithm>
using namespace std;

long long N, R, A;
long long g[100005], e[100005];

long long csum = 0, nsum = 0, ans = 0;
pair<int, long long> inc[100005];

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N >> R >> A;
    nsum = N * A;

    for(int i=0; i<N; i++){
        cin >> g[i] >> e[i];
        csum += g[i];
        inc[i] = make_pair(e[i], R - g[i]);
    }

    sort(inc, inc+N);
    for(int i=0; i<N; i++){
        if(csum >= nsum) break;
        long long take = min(inc[i].second, nsum - csum);
        csum += take;
        ans += take * inc[i].first;
    }

    cout << ans << endl;
}