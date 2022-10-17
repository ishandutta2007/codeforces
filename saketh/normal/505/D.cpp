#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXV = 100005;

int P[MAXV];
int R[MAXV];
int S[MAXV];

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

int N, M;
vector<int> fam[MAXV];
vector<int> inc[MAXV];
int out[MAXV];

int topo(int who){
    if(fam[who].size() == 0) return 0;

    int proc = 0;
    
    queue<int> q;
    for(int v : fam[who])
        if(out[v] == 0)
            q.push(v);

    while(!q.empty()){
        int v = q.front(); q.pop();
        proc++;

        for(int p : inc[v]){
            --out[p];
            if(out[p] == 0) q.push(p);
        }
    }


    if(proc == fam[who].size()) return fam[who].size() - 1;
    return fam[who].size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    init(N);

    for(int i=0; i<M; i++){
        int A, B;
        cin >> A >> B; A--;B--;
        inc[B].push_back(A);
        out[A]++;
        unio(A, B);
    }

    for(int i=0; i<N; i++){
        int who = rep(i);
        fam[who].push_back(i);
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        int edge = topo(i);
        ans += edge;
    }
    cout << ans << endl;

    return 0;
}