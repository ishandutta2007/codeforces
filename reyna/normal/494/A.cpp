//In the name of God
#include <iostream>
using namespace std;
int main(){
    string S;
    cin >> S;
    int cnt = 0;
    int in = 0;
    int out = 0;
    int last = -1;
    for(int i = 0; i < S.size();i++){
        if(S[i] == ')')
            out++;
        else if(S[i] == '(')
            in++;
        else{
            cnt++;
            last = i;
        }
        if(out + cnt - in > 0){
            cout << -1 << endl;
            return 0;
        }
    }
    int tin = 0,tout = 0;
    for(int i = S.size()-1; i > last;i--){
        if(S[i] == ')')
            tout++;
        else
            tin++;
        if(tin > tout){
            cout << -1 << endl;
            return 0;
        }
    }
    if(tin > tout){
        cout << -1 << endl;
        return 0;
    }
//  cout << cnt << " " << in << " " << out << endl;
    if(cnt > (in - out)){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < cnt;i++){
        if(i == cnt-1){
            cout << ((in-out)-cnt)+1 << endl;
        }else{
            cout << 1 << endl;
        }
    }
    return 0;
}