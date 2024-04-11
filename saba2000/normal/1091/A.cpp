#include<bits/stdc++.h>
using namespace std;
main(){
    int a, b,c;
    cin >> a >> b >> c;
    cout <<max(0, min(a, min(b - 1, c - 2)) * 3 + 3 )<<endl;
}