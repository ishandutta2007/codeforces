#include <iostream>
#include <stdlib.h>
using namespace std;

string arg;
int pow[4][4] = {{1, 1, 1, 1},
                 {1, 2, 4, 8},
                 {1, 3, 9, 27},
                 {1, 4, 16, 64}};

int main(){
    ios_base::sync_with_stdio(false);
    cin >> arg;

    if(arg.length() > 2)
        arg = arg.substr(arg.length()-2);

    int exp = atoi(arg.c_str()) % 4;
    cout << (pow[0][exp]+pow[1][exp]+pow[2][exp]+pow[3][exp])%5 << endl;
    return 0;
}