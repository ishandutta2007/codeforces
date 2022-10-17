#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;

int N, M;
vector<int> adj[MAXN];

int fir1[MAXN];
int sec1[MAXN];

void calc1(int loc){
    if(adj[loc].size() == 0) {
        M++;
        fir1[loc] = 1;
        sec1[loc] = 1;
    }
    
    else {
        fir1[loc] = N;
        for(int c : adj[loc]){
            calc1(c);
            fir1[loc] = min(fir1[loc], sec1[c]);
            sec1[loc] += fir1[c];
        }
    }

}

int fir2[MAXN];
int sec2[MAXN];

void calc2(int loc){
    if(adj[loc].size() == 0) {
        fir2[loc] = 1;
        sec2[loc] = 1;
    }
    
    else {
        sec2[loc] = N; 
        for(int c : adj[loc]){
            calc2(c);
            sec2[loc] = min(sec2[loc], fir2[c]);
            fir2[loc] += sec2[c];
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N-1; i++){
        int a, b; 
        cin >> a >> b; 
        adj[a-1].push_back(b-1);
    }

    calc1(0);
    cout << M-fir1[0]+1 << endl;
    calc2(0);
    cout << fir2[0] << endl;
}