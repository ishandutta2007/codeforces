#include <iostream>
using namespace std;

string num;

int main(){
    cin >> num;
    for(int i=0; i<num.size(); i++){
        int dig = num[i] - '0';
        int rep = 9 - dig;
        if(i == 0 && rep == 0) continue;
        if(rep >= dig) continue;
        num[i] = '0' + rep;
    }

    cout << num << endl;
}