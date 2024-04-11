#include<iostream>
#include<string>
using namespace std;

string str;
int cnt[3];
bool first = true;

int main(){
    cin >> str;
    for(int c=0; c<str.length(); c+=2)
        cnt[str[c]-'1']++;
    for(int c=0; c<cnt[0]; c++){
        if(!first) cout << "+";
        first = false;
        cout << "1";
    }
    for(int c=0; c<cnt[1]; c++){
        if(!first) cout << "+";
        first = false;
        cout << "2";
    }
    for(int c=0; c<cnt[2]; c++){
        if(!first) cout << "+";
        first = false;
        cout << "3";
    }
    cout << endl;
    return 0;
}