#include <iostream>
using namespace std;

int N, M, B, V;
int bugs[512];

int ways[512][512];

int main(){
    cin >> N >> M >> B >> V;
    for(int i=0; i<N; i++)
        cin >> bugs[i];

    ways[0][0] = 1;

    for(int i=0; i<N; i++)
        for(int lw=0; lw<M; lw++)
            for(int bw=0; bw<=B; bw++){
                if(bw + bugs[i] > B) continue;
                ways[lw+1][bw+bugs[i]] = (ways[lw+1][bw+bugs[i]] + ways[lw][bw]) % V;
            }

    int ans = 0;

    for(int bw=0; bw<=B; bw++)
        ans = (ans + ways[M][bw]) % V;

    cout << ans << endl;
}