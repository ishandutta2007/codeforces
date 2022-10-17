#include <iostream>
#include <iomanip>
using namespace std;

int N, M;
string str[64];
long long amb[1<<20];
double prb[1<<20];

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> str[i];
    M = str[0].length();

    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++){
            int sim = 0;
            for(int k=0; k<M; k++)
                if(str[i][k] == str[j][k])
                    sim |= 1 << k;

            amb[sim] |= 1LL << i;
            amb[sim] |= 1LL << j;
        }

    for(int i=(1<<M)-1; i>=0; i--)
        for(int j=0; j<M; j++)
            if((i>>j)&1)
                amb[i ^ (1<<j)] |= amb[i];

    double ans = 0;
    prb[0] = 1;

    for(int i=0; i<(1<<M); i++){
        for(int j=0; j<M; j++)
            if(!((i>>j)&1))
                prb[i ^ (1<<j)]
                    += prb[i] / (M - __builtin_popcount(i));

        ans += prb[i] * __builtin_popcountll(amb[i]) / ((double) N);
    }

    cout << fixed << setprecision(20);
    cout << ans << endl;
    return 0;
}