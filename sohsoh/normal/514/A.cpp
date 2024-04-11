#include <iostream>

using namespace std;

int main(){
    long long int n, a = 0, m = 1;
    cin >> n;
    while(n > 0){
        int t = n % 10;
        if(t > 4 && !(n / 10 == 0 && t == 9))
            t = 9 - t;
        a += t * m;
        m *= 10;
        n /= 10;
    }
    cout << a << endl;
    return 0;
}