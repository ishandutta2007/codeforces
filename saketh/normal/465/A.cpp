#include <iostream>
using namespace std;

int N, c=0;
string inp;

int main(){
    cin >> N >> inp;

    for(int i=0; i<N; i++){
        c++;
        if(inp[i] == '0') break;
    }

    cout << c << endl;
    return 0;
}