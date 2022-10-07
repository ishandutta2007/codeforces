#include<bits/stdc++.h>
using namespace std;
long long p[100009];
main(){
    long long n, m , k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> p[i];
    }
    long long  j = 1, o = 0;
    for(int i = 1;i <= m; i++){
        if((p[i] - j) / k == (p[j] - j) / k) continue;
        else {o++; j = i;}
    }
    cout << o +1<<endl;

}