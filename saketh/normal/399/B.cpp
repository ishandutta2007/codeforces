#include <iostream>
using namespace std;

int N; string s;
long long ans = 0;

int main(){
    cin >> N >> s;
    for(int i=N-1; i>=0; i--){
        ans *= 2;
        ans += s[i]=='R';
    }

    cout << ((1LL<<N)-1-ans) << endl;
    return 0;
}