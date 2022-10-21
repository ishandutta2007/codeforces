#include <bits/stdc++.h>
using namespace std;

string str;
int cnt[15];

int main(){
    int n;
    cin >> n;
    cin >> str;
    for(char c : str){
        cnt[c - '0'] ++;
    }
    cout << min(cnt[8], n / 11);
}