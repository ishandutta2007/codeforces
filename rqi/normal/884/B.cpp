#include <iostream>

using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        long long  a;
        cin >> a;
        sum+=a;
    }
    sum+=n-1;
    if(sum == x){
        cout << "YES";
    }
    else cout << "NO";
}