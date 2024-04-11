#include <iostream>
using namespace std;

int N, m1, m2 = 0x7fffffff;
int v[128];

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> v[i];
        if(i>0) m1 = max(m1, v[i] - v[i-1]);
        if(i>1) m2 = min(m2, v[i] - v[i-2]);
    }

    cout << max(m1, m2) << endl;
}