#include <iostream>
using namespace std;

int N, L, R, X;
int ans = 0;
int v[20];

int main(){
    cin >> N >> L >> R >> X;
    for(int i=0; i<N; i++) cin >> v[i];

    for(int m=0; m<(1<<N); m++){
        int sum = 0;
        int low = 0x7f7f7f7f;
        int hig = 0;

        for(int i=0; i<N; i++)
            if((m>>i)&1){
                sum += v[i];
                low = min(low, v[i]);
                hig = max(hig, v[i]);
            }

        if(sum >= L && sum <= R && (hig-low) >= X)
            ans++;
    }

    cout << ans << endl;
}