#include<bits/stdc++.h>
using namespace std;
main(){
    int ans = 0;
    for(int i =0; i <= 9; i++){
        cout << i << endl;
        string s;
        fflush(stdout);
        getline(cin, s);
        if((s[0] =='d' && s.back() =='n') || s[0] == 'a' || s[0] == 't' || (s[0] == 'g' && s[1] =='o')  || s[0] == 'w' || (s[0] =='n' && s.back()=='y' ))
        {
            cout <<"grumpy"<<endl;
            return 0;
        }
        if((s[0] == 'd' && s.back()!='n') || (s[0] =='n' && s.back() =='d') ||  (s[0] =='g' && s[1] =='r') || s[0] =='c'){
             cout <<"normal"<<endl;
             return 0;
        }
    }
    }