//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 1e5 + 2;
int arr[Maxn];
int main(){
    int n;
    cin >> n;
    int div = 1;
    for(int i = 0; i < n-1;i++){
        div *= 10;
        div %= 7;
    }
    div += 20;
    div %= 7;
    int k = 20;
    while(div % 7){
        div += 30;
        div %= 7;
        k+=30;
    }
    if(n == 1 || n == 2){
        cout << -1 << endl;
        return 0;
    }
    arr[n-1] = 1;
    for(int i = 0; i < n;i++){
        arr[i] += k % 10;
        arr[i+1] += arr[i] / 10;
        k /= 10;
    }
    for(int i = n-1; i >= 0;--i){
        cout << arr[i];
    }
    cout << endl;
    return 0;
}