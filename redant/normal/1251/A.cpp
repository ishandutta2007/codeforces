#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        vector<int> f(26, 0);
        int j = 0;
        for (int i = 0; i < s.length(); i = j) {
            j = i + 1;
            while (j < s.length()  && s[i] == s[j])
                j++;
            if ((j-i)&1)
                f[s[i]-'a']=1;
        }        
        for (char c = 'a'; c <= 'z'; c++)
            if (f[c-'a']) cout << c;
        cout << endl;
    }

    return 0;
}