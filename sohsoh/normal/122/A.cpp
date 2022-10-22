#include <iostream>

using namespace std;

bool is_lucky(int inp){
    while(inp > 0){
        if(inp % 10 != 4 && inp % 10 != 7)
            return false;
        inp /= 10;
    }
    return true;
}

int main(){
    int b;
    cin >> b;
    if(is_lucky(b)){
        cout << "YES" << endl;
        return 0;
    }
    for(int i = 1; i <= 1000; i++){
        if(is_lucky(i))
            if(b % i == 0){
                cout << "YES" << endl;
                return 0;
            }
    }
    cout << "NO" << endl;
    return 0;
}