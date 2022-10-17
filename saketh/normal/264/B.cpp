#include<iostream>
#define MAXN 100005
#define MAXV 100000
using namespace std;

int N, V, L=1;
int f[MAXN]; //f[n] = smallest prime factor of n
int b[MAXN]; //b[f] = length of longest good sequence whose last entry is divisible by f

int main(){
    for(int p=2; p<=MAXV; p++){
        if(f[p]) continue;
        for(int m=p; m<=MAXV; m+=p)
            if(!f[m]) f[m] = p;   
    }
    
    cin >> N;
    
    for(int n = 0; n<N; n++){
        cin >> V;
        int l = 0;
        for(int o=V; o!=1; o/=f[o])
            l = max(l, 1+b[f[o]]);
        for(int o=V; o!=1; o/=f[o])
            b[f[o]] = l;        
        L = max(L, l);
    }
    
    cout << L << endl;
}