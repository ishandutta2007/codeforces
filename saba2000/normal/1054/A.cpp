#include<bits/stdc++.h>
using namespace std;
main(){
    int x, y, z, t1, t2, t3;
    cin>>x>>y>>z>>t1>>t2>>t3;
    int T1 = abs(x-y)*t1;

    int T2 = 3*t3+abs(x-z)*t2+abs(y-x)*t2;
    if(T2 <= T1) cout << "YES"<<endl;
    else cout << "NO"<<endl;
}