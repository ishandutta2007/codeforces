#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ans = 10;
        for(int i = 0; i < (1<<10); i++){
            int ok = 1;
            for(int j = 0; j < 10; j++){
                if(s[j] == '0' && (1<<j)&i) ok = 0;
                if(s[j] == '1' && !((1<<j)&i)) ok = 0;
            }
            if(!ok) continue;
            int a=0,b=0,A=5,B=5;
            for(int j = 0; j< 10; j++){
                if(j%2 == 0) {A--; if((1<<j)&i) a++;}
                else {B--; if((1<<j)&i) b++;}
                if(a > B+b || b > a+A) ans = min(ans, j + 1);
            }
        }
        cout<<ans<<endl;
    }

}