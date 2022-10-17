#include <iostream>
#include <map>
using namespace std;

int N;
string s;
map<char, int> ct;

int main(){
    cin >> N >> s;

    int M = 0;
    for(char c : s)
        M = max(M, ++ct[c]);

    int ch = 0;
    for(auto p : ct)
        if(p.second == M)
            ch++;

    long long ans = 1;
    for(int i=0; i<N; i++)
        ans = (ans * ch) % 1000000007;

    cout << ans << endl;
}