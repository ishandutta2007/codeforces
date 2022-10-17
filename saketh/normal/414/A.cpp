#include <iostream>
using namespace std;

typedef long long ll;

const int MAXV = 10 * 1000 * 1000;
ll N, K;
int sieve[MAXV + 5];

bool extra = false;

int main(){
    cin >> N >> K;
    if(N == 1 && K != 0){ cout << -1 << endl; return 0; }
    if(N%2){ extra = true; N--; }


    sieve[1] = -1;
    for(ll p=2; p<=MAXV; p++)
        if(sieve[p]) continue;
        else for(ll q=p; q<=MAXV; q+=p)
            sieve[q] = p;


    ll EX = K - (N-2)/2;
    if(EX <= 0){ cout << -1 << endl; return 0; }

    if(N > 1) cout << EX << " " << 2*EX << " ";
    for(ll i=3, p = 0; p < N-2; i++){
        if(sieve[i] != i) continue;
        if(i == EX) continue;
        cout << i << " ";
        p++;
    } 

    if(extra) cout << 999999937;
    cout << endl; 
    return 0;
}