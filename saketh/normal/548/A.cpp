#include <iostream>
using namespace std;

string s;
int k;

int main(){
    cin >> s >> k;

    if(s.length() % k){
        cout << "NO" << endl;
        return 0;
    }

    k = s.length() / k;
    bool good = true;
    
    for(int i=0; i<s.length(); i+=k)
        for(int j=i; j<i+k; j++)
            good &= s[j] == s[i+k-1-j+i];
    
    cout << (good ? "YES" : "NO") << endl;
}