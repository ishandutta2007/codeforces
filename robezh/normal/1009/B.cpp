#include <bits/stdc++.h>
using namespace std;

string s;
int cnt1 = 0;
bool alw = false;
vector<int> res;

int main() {
    getline(cin, s);
    for(char c : s){
        int now = c - '0';
        if(now == 1) cnt1 ++;
        else res.push_back(now);
    }
    for(int x : res){
        if(x != 0 && !alw){
            for(int i = 0; i < cnt1; i++) cout << 1;
            cout << x;
            alw = true;
        }
        else cout << x;
    }
    if(!alw) for(int i = 0; i < cnt1; i++) cout << 1;
}