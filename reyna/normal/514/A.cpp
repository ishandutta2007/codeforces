//In the name of God
#include <iostream>
using namespace std;
int main(){
    string S;
    cin >> S;
    string ans = "";
    for(int i = 0; i < S.size();i++){
        if(!i && S[i] == '9' || !i && S[i] == '0'){
            ans +='9';
        }else
            ans += min(9-(S[i]-'0')+'0',(int)S[i]);
    }
    bool f = 0;
    for(int i = 0; i < ans.size();i++){
        if(ans[i] != '0')
            f = 1;
        if(f){
            cout << ans[i];
        }
    }
    if(f == 0)
        cout << 9;
    cout << endl;
    return 0;
}