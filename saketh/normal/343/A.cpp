#include <iostream>
using namespace std;

long long calc(long long a, long long b){
    if(a == b) return 1;

    if(a < b){
        long long c = a;
        a = b;
        b = c;
    }

    if(b == 0) return 0;

    return (a - a%b)/b + calc(a%b, b);
}


int main(){
    long long a, b;
    cin >> a >> b;
    cout << calc(a, b) << endl;
    return 0;
}