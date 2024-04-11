#include<bits/stdc++.h>
using namespace std;
main(){
    char a,b;
    cin >> a >> b;
    bool flag = 0;
    for(int i = 0; i < 5; i++){
        char x,y;
        cin >> x >> y;
        if(x == a || y == b)flag = 1;
    }
    if(flag) cout << "YES"<<endl;
    else cout <<"NO"<<endl;
}