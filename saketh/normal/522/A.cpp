#include <iostream>
#include <map>
using namespace std;

int N, M = 1;
map<string, int> chain;

string lower(string s){
    for(int i=0; i<s.length(); i++)
        if(s[i] <= 'Z')
            s[i] += 'a' - 'A';
    return s;
}

int main(){
    chain["polycarp"] = 1;

    cin >> N;
    for(int i=0; i<N; i++){
        string a, b, c;
        cin >> a >> b >> c;

        a = lower(a);
        c = lower(c);

        chain[a] = 1 + chain[c];
        M = max(M, chain[a]);
    }

    cout << M << endl;
}