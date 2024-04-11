#include <iostream>
using namespace std;
int main(){
    int a, b, c, res = 0, n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b >> c;
        if(a + b + c > 1){
            res++;
        }
    }
    cout << res;
}