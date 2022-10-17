#include <iostream>
using namespace std;

int N;
string a, b;

int main(){
    cin >> a >> b;
    N = a.size();

    int dif = 0;
    for(int i=0; i<N; i++)
        dif += a[i] != b[i];

    if(dif % 2){
        cout << "impossible" << endl;
        return 0;
    }    

    int pas = 0;
    for(int i=0; i<N; i++){
        if(a[i] == b[i]) cout << '0';
        else{
            if(pas < dif/2) cout << a[i];
            else cout << b[i];
            pas++;
        }
    }

    cout << endl;
}