#include <iostream>
using namespace std;

long long N, A;
long long S;
long long dice[1000005];

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N >> A;

    for(int i=0; i<N; i++){
        cin >> dice[i];
        S += dice[i];
    }

    for(int i=0; i<N; i++){
        long long L = max(1ll, A - (S - dice[i]));
        long long H = min(dice[i], A - (N - 1)); 
        cout << dice[i] - (H - L + 1) << " ";
    }

    cout << endl;
}