#include <iostream>
using namespace std;
int main(){
    int max = -1000000000;
    int k;
    int n;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        int f,t;
        cin >> f >> t;
        if(t > k){
            f = f-(t-k);
        }
        if(f > max){
            max = f;
        }
    }
    cout << max;
    return 0;
}