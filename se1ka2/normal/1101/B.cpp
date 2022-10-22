#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int d[4];
    fill(d, d + 4, -1);
    for(int i = 0; i < n; i++){
        if(d[0] == -1 && s[i] == '[') d[0] = i;
        if(d[0] != -1 && s[i] == ':'){
            d[1] = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(d[3] == -1 && s[i] == ']') d[3] = i;
        if(d[3] != -1 && s[i] == ':'){
            d[2] = i;
            break;
        }
    }
    if(d[1] == -1 || d[2] == -1 || d[1] >= d[2]){
        cout << -1 << endl;
        return 0;
    }
    int l = 0;
    for(int i = d[1] + 1; i < d[2]; i++){
        if(s[i] == '|') l++;
    }
    cout << 4 + l << endl;
}