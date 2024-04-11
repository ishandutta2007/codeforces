#include <cstdio>
#include <iostream>
using namespace std;

int ans;
string in;
bool ct[26];

int main(){
    cin >> in;
    for(int i = 0; i < (int)in.size(); i++) ct[in[i] - 'a'] = true;
    for(int i = 0; i < 26; i++) if(ct[i]) ans++;
    if(ans & 1) printf("IGNORE HIM!\n");
    else printf("CHAT WITH HER!\n");
    return 0;
}