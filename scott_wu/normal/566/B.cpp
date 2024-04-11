#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const int MAXN = 30300; 

int N;
int proc[MAXN];
vector<int> in[MAXN];

bool done[4*MAXN];
int ops[4*MAXN][3];
set<int> legal;

int comp_net(int i, int wp) {
    int res = 0;
    if(ops[i][0] == wp) res--;
    if(ops[i][1] == wp) res++;
    if(ops[i][2] == wp) res++;
    return res;
}

bool cando(int op) {
    if(done[op]) return false;
    int B = ops[op][1];
    int C = ops[op][2];
    if(comp_net(op, B) + proc[B] > 9) return false;
    if(comp_net(op, C) + proc[C] > 9) return false;
    return true;
}

void dec(int serv) {
    proc[serv]--;
    for (int wo : in[serv]) {
        if(cando(wo)){
            legal.insert(wo);
        }
    }
}

void inc(int serv) {
    proc[serv]++;
    for (int wo : in[serv]) {
        if(!cando(wo)) {
            legal.erase(wo);
        }
    }
}

int main(){
    setup();

    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        proc[i] = 4;
    }
    
    for (int i = 0; i < 4*N; i++) {
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
        in[ops[i][1]].push_back(i);
        if(ops[i][2] != ops[i][1])
            in[ops[i][2]].push_back(i);
        legal.insert(i); 
    }

    cout << "YES\n";

    while (legal.size() > 0) {
        int wo = *legal.begin();
        done[wo] = true;
        legal.erase(wo); 
        
        int A = ops[wo][0];
        int B = ops[wo][1];
        int C = ops[wo][2];

        cout << wo+1 << " ";
        
        dec(A);
        inc(B);
        inc(C);
    }    

    cout << "\n";
}