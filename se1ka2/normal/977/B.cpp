#include <iostream>
#include <string>
#include <map>
using namespace std;

int c[26][26];

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n - 1; i++){
        c[s[i] - 'A'][s[i + 1] - 'A']++;
    }
    int l = 0;
    int ai = -1, aj = -1;
    for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++){
        if(c[i][j] > l){
            l = c[i][j];
            ai = i;
            aj = j;
        }
    }
    cout << char('A' + ai) << char('A' + aj) << endl;
}