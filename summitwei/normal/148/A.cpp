#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    int count = 0;

    for(int i=1; i<n+1; i++){
        if(i % a == 0 || i % b == 0 || i % c == 0 || i % d == 0){
            count++;
        }
    }

    cout << count;
    return 0;
}