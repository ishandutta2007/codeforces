#include <iostream>

using namespace std;

int main() {
    long long n, t;
    long long a;
    cin >> n >> t;
    long long time = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        time += 86400-a;
        if(time >= t){
            cout << i+1;
            break;
        }
    }
}