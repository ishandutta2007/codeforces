#include <iostream>
using namespace std;
int main(){
    long long n,m,a;
    cin >> n >> m >> a;
    if(n % a != 0){
        n = n - (n % a) + a;
    }
    if(m % a != 0){
        m = m - (m % a) + a;
    }
    cout << (m/a)*(n/a);
}