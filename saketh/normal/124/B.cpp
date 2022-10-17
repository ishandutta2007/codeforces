#include<iostream>
#include<algorithm>
#define INF 99999999;
using namespace std;

int N, K;
int digs[8][8];
int prm[8];
bool seen[8];
int best = INF;
int vals[8];

int check(){
    for(int n=0; n<N; n++){
        vals[n] = 0;
        for(int d=0; d<K; d++){
            vals[n]*=10;
            vals[n] += digs[n][prm[d]];
        }
    }
    sort(vals, vals+N);
    if(vals[N-1] - vals[0] < best)
        best = vals[N-1] - vals[0];
}

void recur(int d){
    if(d==K) check();
    else{
        for(prm[d] = 0; prm[d]<K; prm[d]++){
            if(!seen[prm[d]]){
                seen[prm[d]] = true;
                recur(d+1);
                seen[prm[d]] = false;
            }
        }
    }
}

int main(){
    cin >> N >> K;
    for(int n=0; n<N; n++){
        int t; 
        cin >> t;
        for(int m=K-1; m>=0; m--){
            digs[n][m] = t%10;
            t/=10;
        }
    }
    recur(0);
    cout << best << endl;
}