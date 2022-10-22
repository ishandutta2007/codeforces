#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int t = n;
    int p2 = 0, p3 = 0;
    while (t != 3 && t != 0){
        t -= 2;
        p2++;
    }
    if(t == 3){
        p3++;
    }
    cout << p2 + p3 << endl;
    for(int i = 0; i < p2; i++){
        cout << "2 ";
    }
    for(int i = 0; i < p3; i++){
        cout << "3 ";
    }
    cout << endl;

    return 0;
}