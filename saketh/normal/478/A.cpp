#include <iostream>
using namespace std;

int main(){
    int sum = 0;

    for(int i=0; i<5; i++){
        int end;
        cin >> end;
        sum += end;
    }

    if(sum % 5 || sum == 0) cout << -1 << endl;
    else cout << sum/5 << endl;

    return 0;
}