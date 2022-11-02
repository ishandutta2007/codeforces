#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int sumA = 0;
    int sumB = 0;
    int sumC = 0;

    for(int i=0; i<N; i++){
        int a, b, c;
        cin >> a >> b >> c;

        sumA += a;
        sumB += b;
        sumC += c;
    }

    if(sumA == 0 && sumB == 0 && sumC == 0){
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}