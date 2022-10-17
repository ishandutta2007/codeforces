#include <iostream>
using namespace std;

long long T, N, L, R;

int main(){
    ios_base::sync_with_stdio(false);
    for(cin >> T; T; T--){
        cin >> N >> L >> R;
        long long M = N / L;
        if(M*L <= N && N <= M*R) cout << "Yes\n";
        else cout << "No\n";
    }

    cout.flush();
    return 0;
}