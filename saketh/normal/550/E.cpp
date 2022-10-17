#include <iostream>
#include <vector>
using namespace std;

int N;
string str;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    str.resize(N);
    for(char &c : str) cin >> c;

    int fzero = str.find('0');
    if(fzero == string::npos){ cout << "NO\n"; return 0; }

    if(fzero == str.size()-1){
        cout << "YES\n";
        for(int i=0; i<fzero; i++)
            cout << "1->";
        cout << 0 << endl;
        return 0;
    }

    if(fzero >= str.size()-2 || str.back() != '0'){ cout << "NO\n"; return 0;}

    cout << "YES\n((";
    for(int i=0; i<fzero; i++)
        cout << "1->";
    cout << "0)->(";
    for(int i=fzero+1; i<N-2; i++)
        cout << str[i] << "->";
    cout << str[N-2] << "))";
    cout << "->0";
    cout << endl;
}