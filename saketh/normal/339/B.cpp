#include<iostream>
using namespace std;

int N, M, loc = 1, tsk, dif;
long long t = 0;

int main(){
    cin >> N >> M;
    for(int m=0; m<M; m++){
        cin >> tsk;
        dif = tsk - loc;
        if(dif < 0) dif += N;
        t += dif;
        loc = tsk;
    }
    cout << t << endl;
    return 0;
}