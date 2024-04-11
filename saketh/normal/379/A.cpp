#include<iostream>
#include<algorithm>
using namespace std;

int A, B;

int main(){
    cin >> A >> B;
    int F = A;
    int U = 0;
    int ans = 0;
    
    while(F > 0 || U >= B){
        F += U/B;
        U -= (U/B) * B;
        ans += F;
        U += F;
        F = 0;
    }
    
    cout << ans << endl;
    return 0;
}