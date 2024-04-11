#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;
typedef long long ll;

int N;

int eff[MAXN];
ll res[MAXN][2];
ll tmp[MAXN][2];
vector<int> sub[MAXN];

void solve(int loc){
    for(int c : sub[loc]) solve(c);
    
    int K = sub[loc].size();

    for(int i=1; i<=K; i++){
        tmp[i][0] = tmp[i-1][0] + res[sub[loc][i-1]][0];
        tmp[i][1] = tmp[i-1][0] + res[sub[loc][i-1]][1];

        if(i>1){
            tmp[i][0] = max(tmp[i][0], tmp[i-1][1] + res[sub[loc][i-1]][1]);
            tmp[i][1] = max(tmp[i][1], tmp[i-1][1] + res[sub[loc][i-1]][0]);
        }
    }

    res[loc][0] = tmp[K][0];
    res[loc][1] = max(tmp[K][0] + eff[loc],
                      tmp[K][1]);

}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0, par; i<N; i++){
        cin >> par >> eff[i];
        if(par != -1) sub[par-1].push_back(i);
    }

    solve(0);
    cout << max(res[0][0], res[0][1]) << endl;    
}