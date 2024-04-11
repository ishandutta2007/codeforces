#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    long long x;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x % 2 == 1){
            cout << "First";
            ans = 1;
            break;
        }
    }
    if(ans == 0){
        cout << "Second";
    }
    
}