#include<bits/stdc++.h>
#define Fi first
#define Se second
using namespace std;
long long f[10];
main(){
    int n;
    cin >> n;
    int a = (int)sqrt(n);
    int b = n % a;
    int c = n/a - b;
    //b - a+1
    //c - a
    for(int i = 0; i < b; i++){
        int x = n - (a + 1) * (i+1) + 1;
        for(int j = 0; j < a+1; j++)
            cout<<x++<<" ";
    }
    for(int i = 0; i < c; i++){
        int x = n - a * (i+1) + 1 - (a+1)*b;
        for(int j = 0; j < a; j++)
            cout<<x++<<" ";
    }
}
//01
//00
//