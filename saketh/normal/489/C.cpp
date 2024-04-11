#include <iostream>
using namespace std;

int M, S;

int main(){
    cin >> M >> S;

    if(M == 1 && S == 0){
        cout << "0 0" << endl;
        return 0;
    }


    if(S == 0 || S > 9*M){
        cout << "-1 -1" << endl;
        return 0;
    }

    string low = "";

    int T = S;
    for(int i=0; i<M; i++){
        int dig = i?0:1;
        dig = max(dig, T - 9 * (M-1-i));
    
        T -= dig;
        low += ('0' + dig);
    }

    string high = "";

    T = S;
    for(int i=0; i<M; i++){
        int dig = min(9, T);
        T -= dig;
        high += ('0' + dig);
    }

    cout << low << " " << high << endl;
    return 0;
}