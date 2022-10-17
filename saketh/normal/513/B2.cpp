#include <iostream>
using namespace std;

typedef long long ll;

ll N, M;
int res[64];

int main(){
    cin >> N >> M;
    M--;

    int i = 0, j = N-1;

    for(int k=1; k<N; k++){
        ll pw = 1ll << (N-k-1);
        if(M >= pw){
            res[j--] = k;
            M -= pw;
        }
        else res[i++] = k;
    }

    res[i] = N;

    for(int k=0; k<N; k++)
        cout << res[k] << " ";
    cout << endl;
}