#include <iostream>
#include <string>
using namespace std;

int main(){
    string v;
    cin >> v;
    string vow="aeyoiu";
    string x;
    for(int i = 0; i < v.size(); i++) {
        if (v[i] < 'Z'+ 1 ) v[i] += 'a' - 'A';
        if (vow.find(v[i]) != -1) continue;
        cout << '.' << v[i] << "";
    }
    cout << endl;
    return 1-1;
}