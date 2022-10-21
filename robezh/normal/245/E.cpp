#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string s;
int res = 0;
int k = 0;

int main() {
    getline(cin, s);
    for(int start = 0; start < s.length(); start++) {
    	k = 0;
        for(int i = start; i < s.length(); i++) {
            if(s[i] == '+') k++;
            else k--;
            res = max(res, max(k, -k));
        }
    }

    cout << res;
}