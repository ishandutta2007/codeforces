#include<iostream>
#include<sstream>
using namespace std;

int N;
stringstream ss;
string tmp;
string enc;
string msg;

int main(){
    cin >> N;
    ss << "<3";
    for(int n=0; n<N; n++){
        cin >> tmp;
        ss << tmp;
        ss << "<3";
    }
    msg = ss.str();
    cin >> enc;
    
    int a = 0, b = 0;
    while(a<enc.length() && b<msg.length()){
        if(enc[a] == msg[b]) b++;
        a++;
    }
    if(b == msg.length()) cout << "yes" << endl;
    else cout << "no" << endl;
    
    return 0;
}