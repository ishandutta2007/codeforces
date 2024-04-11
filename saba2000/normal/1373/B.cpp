#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int a =0,b=0;
        for(char x : s)
            if(x =='0') a++;
        else b++;
        cout << (min(a,b) % 2 == 1 ? "DA" : "NET")<<endl;
    }
}