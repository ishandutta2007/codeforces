#include <iostream>

using namespace std;

string f(string s){
for(int i=0;i<s.length();i++){
    if(s[i]=='.') s[i]='0';
}
return s;
}

int main()
{
    int n,p;
    cin >> n >> p;
    string s;
    cin >> s;
    if(p>=n) {cout << "No" << endl; return 0;}
    for(int i=0;i<s.length();i++){
        if(s[i]=='.'){
            if((i+p) < s.length()){
                if(s[i+p]=='.'){
                    s[i]='0';
                    s[i+p]='1';
                    cout << f(s) <<endl;
                    return 0;
                }
                else if(s[i+p]=='0'){
                   s[i]='1';
                    cout << f(s) <<endl;
                    return 0;
                }
                else{
                   s[i]='0';
                    cout << f(s) <<endl;
                    return 0;
                }
            }
            else if((i-p) >= 0){
                if(s[i-p]=='.'){
                    s[i]='0';
                    s[i-p]='1';
                    cout << f(s) <<endl;
                    return 0;
                }
                else if(s[i-p]=='0'){
                   s[i]='1';
                    cout << f(s) <<endl;
                    return 0;
                }
                else{
                   s[i]='0';
                    cout << f(s) <<endl;
                    return 0;
                }
            }
        }
    }
    string prev="2";
    for(int i=0;i<p;i++){
            prev="2";
        for(int j=0;i+j*p<s.length();j++){
        if(prev[0]!='2' && s[i+j*p]!=prev[0] && s[i+j*p]!='.'){
            cout << f(s) <<endl;
                    return 0;
        }
        if(prev[0] == '2') prev[0]=s[i+j*p];
    }
    }
    cout << "No" << endl;
    return 0;
}