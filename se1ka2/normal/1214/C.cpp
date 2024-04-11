#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int les = 0;
    int now = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') now++;
        else now--;
        les = min(les, now);
    }
    if(now != 0 || les < -1) cout << "No" << endl;
    else cout << "Yes" << endl;
}