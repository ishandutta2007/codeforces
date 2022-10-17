#include <iostream>
using namespace std;

string s;


int main(){
    cin >> s;
    
    while(s.length()){
        size_t idx = s.find("WUB");
        
        if(idx == string::npos){
            cout << s << endl;
            break;
        }
       
        if(idx>0) cout << s.substr(0, idx) << " ";
        s = s.substr(idx+3); 
    }

    cout << endl;
}