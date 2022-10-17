#include <iostream>
using namespace std;

long long N;
long long A, B;
long long L, H;

int main(){
    cin >> N >> A >> B;

    if(A * B >= 6*N){
        cout << A*B << endl;
        cout << A << " " << B << endl;
        return 0;
    }

    L = min(A, B);
    H = max(A, B);

    for(long long prod = 6*N; ; prod++)
        for(long long low = L; low * low <= prod; low++)
            if(prod % low == 0 && prod / low >= H){
                cout << prod << endl;
                long long a = low, b = prod/low;
                if(a < A || b < B) cout << b << " " << a << endl;
                else cout << a << " " << b << endl;
                return 0;
            }

    return 0;
}