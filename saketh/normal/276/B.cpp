#include<iostream>
using namespace std;

int a[26], b;

int main(){
    for(char t; cin >> t; a[t-'a']++);
    for(int c=0; c<26; c++) b += a[c]%2;
    if(b%2 || !b) cout << "First" << endl;
    else cout << "Second" << endl;
}