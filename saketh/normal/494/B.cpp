#include <iostream>
using namespace std;

const int MOD = 1000000007;
const int MAXL = 100005;

int N, M;
string A, B;
int succ[MAXL];
bool match[MAXL];

long long dpc[MAXL], pre[MAXL], meg[MAXL];

int main(){
    cin >> A >> B;
    N = A.length();
    M = B.length();


    succ[0] = -1;
    succ[1] = 0;
    int cnd = 0;

    for(int i=2; i<=M; ){
        if(B[i-1] == B[cnd]) succ[i++] = ++cnd;
        else if(cnd) cnd = succ[cnd];
        else succ[i++] = 0;
    }

    int ans = 0, i = 0;

    for(int m=0; i+m<N;){
        if(i<M && B[i] == A[i+m]){
            if(i == M-1) match[m+i] = true;
            i = i+1;
        }
        else if(succ[i]>-1){
            m = m + i - succ[i];
            i = succ[i];
        }
        else{
            i = 0;
            m++;
        }
    }

    dpc[0] = 0;
    pre[0] = 0;
    meg[0] = 0;
    int mr = -1;

    for(int i=1; i<=N; i++){
        if(match[i-1]) mr = (i-M);

        if(mr != -1)
            dpc[i] = (meg[mr] + mr + 1) % MOD;
        pre[i] = (pre[i-1] + dpc[i]) % MOD;
        meg[i] = (meg[i-1] + pre[i]) % MOD;
    }

    cout << (pre[N]) << endl;
    return 0;
}