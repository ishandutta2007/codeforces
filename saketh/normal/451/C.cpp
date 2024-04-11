#include <iostream>
using namespace std;

long long T, N, K, D1, D2;

int main(){
    ios_base::sync_with_stdio(false);

    for(cin >> T; T; T--){
        cin >> N >> K >> D1 >> D2;
        bool can = false;

        for(long long a = -1; a <= 1; a += 2)
            for(long long b = -1; b <= 1; b += 2){
                long long t1 = 0;
                long long t2 = t1 + a * D1;
                long long t3 = t2 + b * D2;

                long long shift = min(min(t1, t2), t3);
                t1 -= shift;
                t2 -= shift;
                t3 -= shift;
                    
                long long tot = t1 + t2 + t3;
                long long rem = K - tot;
                if(rem < 0 || rem % 3) continue;
                
                t1 += rem/3;
                t2 += rem/3; 
                t3 += rem/3;

                if(N % 3) continue;
                long long win = N / 3;

                if(t1 > win) continue;
                if(t2 > win) continue;
                if(t3 > win) continue;

                can = true;
            }

        if(can) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }

    cout.flush();
    return 0;
}