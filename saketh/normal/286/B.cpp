#include <iostream>
using namespace std;

const int MAXN = 1000005;

int N;
int val[MAXN];
int inv[2*MAXN];
int res[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        val[i] = i;
        inv[i] = i;
    }
    
    for(int k=2; k<=N; k++){
        for(int z=(N-1)-(N-1)%k; z>=0; z-=k){
            int w = inv[k-2+z];
            int g = min(k, N-z);
            val[w] += g;
            inv[val[w]] = w;
        }
    }

    for(int i=0; i<N; i++)
        cout << inv[N-1+i] + 1 << " ";
    cout << endl;
}