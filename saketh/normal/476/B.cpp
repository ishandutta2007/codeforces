#include <iostream>
#include <cmath>
using namespace std;

string a, b;
double fact[11];

double ncr(int n, int k){
    double bot = fact[k] * fact[n-k];
    return fact[n] / bot;
}

int main(){
    fact[0] = 1.0;
    for(int i=1; i<=10; i++)
        fact[i] = i * fact[i-1];

    cin >> a >> b;
    int o1 = 0, o2 = 0, q = 0;

    for(int i=0; i<a.length(); i++){
        if(a[i] == '+') o1++;
        else o1--;

        if(b[i] == '+') o2++;
        else if(b[i] == '-') o2--;
        else q++;
    }

    cout.precision(20);

    int dif = o1 - o2;

    if(dif > q || dif < -1 * q || ((q+dif) % 2)) cout << 0. << endl;
    else cout << ncr(q, (q+dif)/2) / pow(2, q) << endl;

    return 0;
}