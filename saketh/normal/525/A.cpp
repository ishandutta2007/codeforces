#include <iostream>
using namespace std;

int N, A;
string s;

char keys[26];

int main(){
    cin >> N >> s;

    for(int i=0; i<N-1; i++){
        char k = s[2*i];
        keys[k-'a']++;

        char d = s[2*i+1];
        if(keys[d-'A'] == 0) A++;
        else keys[d-'A']--;
    }

    cout << A << endl;
}