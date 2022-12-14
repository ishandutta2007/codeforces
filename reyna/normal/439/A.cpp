#include <iostream>
using namespace std;
int main(){
    int n,d;
    cin >> n >> d;
    int zaman = (n-1) * 10;
    int joke = (n-1) * 2;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        zaman += a;
        if(zaman > d){
            cout << -1;
            return 0;
        }
    }
    joke += (d-zaman)/5;
    cout << joke;
}