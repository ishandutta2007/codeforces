#include <iostream>
using namespace std;

const string KEYS = "qwertyuiopasdfghjkl;zxcvbnm,./";
char dir;
string inp;

int main(){
    cin >> dir >> inp;

    for(int i=0; i<inp.length(); i++){
        int j = KEYS.find(inp[i]);
        j = j + ((dir == 'R')?(-1):1);
        cout << KEYS[j];
    }
    cout << endl;

    return 0;
}