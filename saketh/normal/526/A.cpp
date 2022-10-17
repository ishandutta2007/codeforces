#include <iostream>
using namespace std;

int N;
string s;

int main(){
    cin >> N >> s;

    for(int i=0; i<s.length(); i++){
        if(s[i] != '*') continue;
        for(int k=1; i+4*k<s.length(); k++){
            bool good = true;
            for(int j=1; j<=4; j++)
                good &= s[i+j*k] == '*';
            if(good){
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    
    cout << "no" << endl;
}