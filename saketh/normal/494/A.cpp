#include <iostream>
using namespace std;

string s;
int L = 0, R = 0, H = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> s;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '(') L++;
        else if(s[i] == ')') R++;
        else H++;
    }

    int st = 0;
    int enc = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(') st++;
        else{
            int rc = 0;
            if(s[i] == ')') rc = 1;
            else{ enc++; if(enc < H) rc = 1; else rc = L - R - H + 1; }
    
            if(rc <= 0){ cout << -1 << endl; return 0; }
            if(rc > st){ cout << -1 << endl; return 0; }
            st -= rc;
        }
    }

    for(int i=0; i<H; i++){
        if(i+1 < H) cout << 1 << "\n";
        else cout << (L - R - H + 1) << "\n";
    }

    cout.flush();
    return 0;
}