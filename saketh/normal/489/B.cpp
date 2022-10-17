#include <iostream>
#include <algorithm>
using namespace std;

int N, b[105];
int M, g[105];

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> b[i];

    cin >> M;
    for(int i=0; i<M; i++)
        cin >> g[i];

    sort(b, b+N);
    sort(g, g+M);

    int gg = 0, ans = 0;
    for(int i=0; i<N; i++){
        while((gg < M) && (g[gg] < (b[i]-1))) gg++;
        if((gg < M) && (g[gg] <= (b[i]+1))){
            ans++;
            gg++;
        }
    }

    cout << ans << endl;
    return 0;
}