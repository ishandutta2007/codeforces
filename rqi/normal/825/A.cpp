#include <iostream>

using namespace std;

int main() {
    int N;
    
    int dig = 0;
    cin >> N;
    string x;
    cin >> x;
    for(int i = 0; i < N; i++){
        
        if(x[i] == '0'){
            cout << dig;
            dig = 0;
        }
        else dig ++;
       
    }
    cout << dig;
    
}