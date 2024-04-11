#include <iostream>
using namespace std;
int main(){
    int A=0,I=0;
    int n;
    cin >> n;
    string pl;
    cin >> pl;
    for(int i = 0; i < n;i++){
        if(pl[i] == 'A')
            A++;
        else if(pl[i] == 'I')
            I++;
    }
    if(I > 1){
        cout << 0 << endl;
        return 0;
    }
    if(I == 1){
        cout << 1 << endl;
        return 0;
    }
    cout << A << endl;
    return 0;
}