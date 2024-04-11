#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    string s;
    cin >> s;
    char C = 'a';
    int A = 0,B=0,Cc=0;
    for (int i = 0; i < s.size(); i++){
        if(s[i] == 'a') A++;
        if(s[i] == 'b') B++;
        if(s[i] == 'c') Cc++;
        if(C == 'a' && s[i] == 'b') {
            C = 'b';
            continue;
        }
        if(C == 'b' && s[i] == 'c'){
            C = 'c';
            continue;
        }
        if(C == s[i]) continue;
        cout << "NO"<<endl;
        return 0;
    }
    if((Cc == A || Cc == B) && A && B && Cc) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}