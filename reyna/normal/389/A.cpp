#include <iostream>
using namespace std;
int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}
int main(){
    int n;
    cin >> n;
    int counter;
    cin >> counter;
    for(int i = 1; i < n;i++){
        int a;
        cin >> a;
        if(a > counter){
            swap(a,counter);
        }
        counter = gcd(counter,a);
    }
    cout << counter * n;
}