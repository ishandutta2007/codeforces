#include <iostream>
using namespace std;

const int MAXN = 505;
const int MAXM = 1005;

int N, M;
int w[MAXN], b[MAXM];
bool seen[MAXN];

long long ans = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0; i<N; i++)
        cin >> w[i];

    for(int i=0; i<M; i++){
        cin >> b[i]; b[i]--;
        for(int j=0; j<MAXN; j++) seen[j] = false;

        for(int k=i-1; k>=0; k--){
            if(b[k] == b[i]) break;
            if(seen[b[k]]) continue;
            ans += w[b[k]];
            seen[b[k]] = true;
        }
    }

    cout << ans << endl;
    return 0;
}