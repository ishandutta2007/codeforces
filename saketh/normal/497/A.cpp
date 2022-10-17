#include <iostream>
using namespace std;

int N, M;

bool gt[1024];
string grid[1024];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for(int i=0; i<N; i++)
        cin >> grid[i];

    int ans = 0;
    for(int j=0; j<M; j++){
        bool good = true;
        for(int i=1; i<N; i++){
            if(gt[i]) continue;
            good &= grid[i][j] >= grid[i-1][j];
        }

        if(!good) ans++;
        else
            for(int i=1; i<N; i++)
                gt[i] |= grid[i][j] > grid[i-1][j];
    }

    cout << ans << endl;
    return 0;
}