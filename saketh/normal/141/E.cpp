#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2000;
const int MAXM = 100005;

int P[2000];
int R[2000];
int S[2000];

void init(){
    for(int i=0; i<1028; i++){
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

int N, M, H;
int u[MAXM], v[MAXM];
char t[MAXM];

int san;
vector<int> edges;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    if( N % 2 == 0){ cout << -1 << endl; return 0; }
    H = (N - 1) / 2;
    init();

    for(int i=0; i<M; i++){
        cin >> u[i] >> v[i] >> t[i];        
        u[i]--;
        v[i]--;
        if(t[i] == 'S') unio(u[i], v[i]);
    }

    for(int i=0; i<M; i++){
        if(t[i] == 'S') continue;
        if(rep(u[i]) == rep(v[i])) continue;
        san++;
        unio(u[i], v[i]);
        edges.push_back(i);
    }

    bool conn = true;
    for(int i=1; i<N; i++)
        conn &= rep(i) == rep(0);
    if(!conn || san > H){ cout << -1 << endl; return 0; }

    init();
    for(int i : edges)
        unio(u[i], v[i]);

    for(int i=0; i<M && san<H; i++){
        if(t[i] == 'S') continue;
        if(rep(u[i]) == rep(v[i])) continue;
        san++;
        unio(u[i], v[i]);
        edges.push_back(i);
    }

    if(san != H){ cout << -1 << endl; return 0; }

    for(int i=0; i<M; i++){
        if(t[i] != 'S') continue;
        if(rep(u[i]) == rep(v[i])) continue;
        unio(u[i], v[i]);
        edges.push_back(i);
    }

    for(int i=1; i<N; i++)
        conn &= rep(i) == rep(0);

    if(conn){
        cout << edges.size() << endl;
        for(int i : edges) cout << i+1 << " ";
        cout << endl;
    }
    else cout << -1 << endl;
}