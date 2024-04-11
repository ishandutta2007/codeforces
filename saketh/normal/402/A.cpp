#include<iostream>
using namespace std;

int main(){
    int k, a, b, v;
    cin >> k >> a >> b >> v;

    int n = 0;
    while(a>0){
        int u = min(k-1, b);
        a -= v * (u+1);
        b -= u;
        n++;
    }

    cout << n << endl;
    return 0;
}