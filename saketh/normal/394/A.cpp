#include <iostream>
using namespace std;
int main() {
    char str[505];
    int N = 0;
    for(char c; cin >> c; N++) {
        str[N] = c;
    }

    int tot = 0, seen = 0; //tot = A+B-C, seen = 1 if we passed =
    int wpl = -1, weq = -1;
    for (int i = 0; i < N; i++) {
        if(str[i] == '+') wpl = i;
        else if (str[i] == '=') weq = i;
        else tot += (weq == -1) ? 1 : -1;
    }

    if(tot == -1) {
    }
    if(tot == -2) {
        str[weq+1] = '=';
        str[weq] = '|';
    } else if (tot == 2) {
        str[weq+1] = '|';
        str[weq-1] = '=';
        str[weq] = '|';
        if(str[weq-2] == '+') {
            str[wpl] = '|';
            str[wpl + 1 - wpl - 1 + weq - 3] = '+';
        }
    } else if (tot == 0) {
    } else { 
        cout << "Impossible\n";
        return 0;
    }

    for(int i=0; i<N; i++)
        cout << str[i];
    cout << endl;
    return 0;
}