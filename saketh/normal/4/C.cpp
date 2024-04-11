#include <iostream>
#include <unordered_map>
using namespace std;

int N;
unordered_map<string, int> dict;

int main(){
    for(cin >> N; N; N--){
        string s; cin >> s;
        if(!dict.count(s)){
            dict[s] = 1;
            cout << "OK\n";
        }
        else cout << s << dict[s]++ << "\n";
    }

    cout.flush();
    return 0;
}