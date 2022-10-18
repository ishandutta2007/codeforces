#include <iostream>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 100005;

int N, D, X, a[MAXN], b[MAXN], r[MAXN], l[MAXN], O = 0;

void shuffle(int *v){
    for(int i=0; i<N; i++){
        X = (X * 37LL + 10007) % MOD;
        swap(v[i], v[X % (i+1)]);
    }
}

void init(){
    for(int i=0; i<N; i++)
        a[i] = i+1;
    shuffle(a);

    for(int i=0; i<N; i++)
        r[a[i]] = i;

    for(int i=0; i<N; i++)
        if(i < D) b[i] = 1;
        else b[i] = 0;
    shuffle(b);

    for(int i=0; i<N; i++)
        if(b[i]) l[O++] = i;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> D >> X;
    init();

    for(int i=0; i<N; i++){
        bool done = false;
        for(int c = N; c>max(N-30, 0); c--)
            if(r[c]<=i && b[i-r[c]]){
                cout << c << "\n";
                done = true;
                break;
            }
        if(done) continue;

        int res = 0;
        for(int j=0; j<O && l[j]<=i; j++)
            res = max(res, a[i-l[j]]);
        cout << res << "\n";
    }

    cout.flush();
    return 0;
}