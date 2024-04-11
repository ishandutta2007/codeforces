#include <iostream>
using namespace std;

int N;
long long L, R;

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> L >> R;
        int ans = __builtin_popcountll(R);
        long long ach = R;

        int digs[62] = {};
        long long tmp = R;

        for(int i=0; tmp; i++){
            digs[i] = tmp % 2;
            tmp /= 2;
        }

        long long val = 0;
        for(int i=61; i>=0; i--){
            if(digs[i]) val += 1LL << i;
            if(!val) continue;
            if(val-1 < L) continue;

            if(__builtin_popcountll(val-1) > ans){
                ans = __builtin_popcountll(val-1);
                ach = val-1;
            }
            else if(__builtin_popcountll(val-1) == ans){
                ach = min(ach, val-1);
            }
        }

        cout << ach << "\n";
    }

    cout.flush();
    return 0;
}