#include<iostream>
#include<string>
using namespace std;

int N;
string s;

int main(){
    for(cin >> N; N; N--){
        cin >> s;
        if(s.length() > 10)
            cout << s[0] << s.length()-2 << s[s.length()-1] << endl;
        else cout << s << endl;
    }
}