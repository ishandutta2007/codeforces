#include <iostream>
using namespace std;

int N, S, D, C;

int main(){
    cin >> N >> S;

    bool can_buy = false;
    int ans = 0;
    for(int i=0; i<N; i++){
        cin >> D >> C;
        if(S > D || (S == D && C == 0))
            can_buy = true;
        if(S > D && C > 0)
            ans = max(ans, 100-C);
    }

    if(!can_buy) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}