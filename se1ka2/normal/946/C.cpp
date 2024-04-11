#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int c = 'a';
    for(int i = 0; i < n; i++){
        if(s[i] <= c){
            s[i] = c;
            c++;
        }
        if(c > 'z') break;
    }
    if(c <= 'z') cout << -1 << endl;
    else cout << s << endl;
}