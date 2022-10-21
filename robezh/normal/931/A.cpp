#include <bits/stdc++.h>
using namespace std;

int a,b;

int main(){
    cin >> a >> b;
    int k = abs(a-b);
    int sum = 0;
    for(int i = 1; i <= k/2; i++){
        sum += i;
    }
    for(int i = 1; i <= k - k/2; i++){
        sum += i;
    }
    cout << sum;
}