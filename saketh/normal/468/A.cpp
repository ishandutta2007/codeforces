#include <iostream>
using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;

    if(N < 4){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES\n";
    int s;
    if(N % 2){
        cout << "1 + 4 = 5\n";
        cout << "5 * 5 = 25\n";
        cout << "25 + 2 = 27\n";
        cout << "27 - 3 = 24\n";
        s = 6;
    }
    else{
        cout << "1 * 2 = 2\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";
        s = 5;
    }

    for(; s<=N; s+=2){
        cout << s+1 << " - " << s << " = 1\n";
        cout << "24 * 1 = 24\n";
    }

    cout.flush();
    return 0;
}