#include<bits/stdc++.h>
using namespace std;
main(){
    string s;
    cin >> s;
    long long ans1 = 0;
    for(int x = 'a'; x <= 'z'; x++){
        for (int y = 'a'; y <= 'z'; y++){
            long long ans = 0, X = 0;
            for(char z : s){
                if(z == y) ans += X;
                if(z == x) X++;
            }
            ans1 = max(ans1, X);
            ans1 = max(ans1, ans);

        }
    }
    cout<<ans1<<endl;



}