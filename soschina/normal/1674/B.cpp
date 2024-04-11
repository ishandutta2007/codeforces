#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int t, cnt;
map<string, int> mp;
string str;

int main(){
    for (char c = 'a'; c <= 'z'; c++)
        for (char d = 'a'; d <= 'z'; d++)
            if(c != d){
                str.clear();
                str.push_back(c);
                str.push_back(d);
                mp[str] = ++cnt;
            }
    scanf("%d", &t);
    while(t--){
        string s;
        cin >> s;
        cout << mp[s] << endl;
    }
    return 0;
}