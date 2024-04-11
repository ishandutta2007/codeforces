#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    string s[100002];
    for(int i = 0; i < n; i++){
        cin >> s[i];
        if(mp[s[i]]) cout << s[i] << mp[s[i]] << endl;
        else cout << "OK" << endl;
        mp[s[i]]++;
    }
}