#include <bits/stdc++.h>
using namespace std;

int n,k;
string str;
set<char> S;

int main() {
    cin >> n >> k;
    getchar();
    getline(cin, str);
    for(char c : str){S.insert(c);}

    if(n < k){
        cout << str;
        for(int i = 0; i < k-n; i++) cout << *(S.begin());
        return 0;
    }
    int pos;
    for(int i = k-1; i >= 0; i--){
        if(str[i] != *(--S.end())){
            pos = i;
            break;
        }
    }
    cout << str.substr(0,pos);
    auto it = S.find(str[pos]);
    it++;
    cout << *it;
    for(int i = 0; i < k-1-pos; i++){
        cout << *(S.begin());
    }
}