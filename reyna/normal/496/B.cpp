//In the name of God
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string S;
    cin >> S;
    string ans = "";
    for(int i = 0; i < n;i++){
        ans+='9';
    }
    for(int i = 0; i < 10;i++){
        for(int j = 0;j < n;j++){
            string now = "";
            for(int k = 0; k < n;k++){
                now += (((S[(j+k)%n] + i - '0') % 10) + '0');
            }
            if(now < ans){
                ans = now;
            }
        }
    }
    cout << ans << endl;
    return 0;
}