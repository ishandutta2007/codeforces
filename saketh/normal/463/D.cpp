#include <iostream>
#include <vector>
using namespace std;

int N, K;
int vals[8][1024];
int idx[8][1024];

vector<int> succ[1024];

bool seen[1024];
int dp[1024];

int calc(int x){
    if(seen[x]) return dp[x];
    seen[x] = true;

    int ans = 1;
    for(int i=0; i<succ[x].size(); i++)
        ans = max(ans, 1 + calc(succ[x][i]));
    return dp[x] = ans;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin >> N >> K;

    for(int i=0; i<K; i++)
        for(int j=0; j<N; j++){
            cin >> vals[i][j];
            vals[i][j]--;
            idx[i][vals[i][j]] = j;
        }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            bool ahead = true;
            for(int k=0; k<K; k++)
                if(idx[k][i] >= idx[k][j])
                    ahead = false;
            if(ahead) succ[i].push_back(j);
        }

    int ans = 0;
    for(int i=0; i<N; i++)
        ans = max(ans, calc(i));
    cout << ans << endl;
    return 0;
}