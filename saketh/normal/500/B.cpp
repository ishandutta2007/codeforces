#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 305;

int P[MAXN];
int R[MAXN];
int S[MAXN];

void init(int N){
    for(int i=0; i<N; i++){
        P[i] = i;
        R[i] = 0;
        S[i] = 1;
    }
}

int rep(int i){
    if(P[i] != i) P[i] = rep(P[i]);
    return P[i];
}

bool unio(int a, int b){
    a = rep(a);
    b = rep(b);
    if(a == b) return false;
    if(R[a] < R[b]){
        P[a] = b;
        S[b] += S[a];
    }
    else{
        P[b] = a;
        S[a] += S[b];
    }
    if(R[a] == R[b]) R[a]++;
    return true;
}

int N, v[MAXN];
char g[MAXN][MAXN];
priority_queue<int> all[MAXN];

int main(){
    init(MAXN);
    cin >> N;
    for(int i=0; i<N; i++) cin >> v[i];

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            cin >> g[i][j];
            if(g[i][j]=='1') unio(i, j);
        }

    for(int i=0; i<N; i++)
        all[rep(i)].push(-v[i]);

    for(int i=0; i<N; i++){
        int fam = rep(i);
        cout << -all[fam].top() << " ";
        all[fam].pop();
    }    

    cout << endl;
    return 0;
}