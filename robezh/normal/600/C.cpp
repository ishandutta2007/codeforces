#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

string str;
int c[180];
char s[200500];
vector<char> V;

int main() {
    fill(c, c + 180, 0);
    getline(cin, str);
    for(int i = 0; i < str.length(); i++) c[str[i]]++;
    for(char i = 'a'; i <= 'z'; i++) {
        if(c[i] % 2) V.push_back(i);
    }
    //if(str.length() % 2 == 1) V.erase(V.end() - 1);
    int l = 0, r = V.size() - 1;
    while(l < r) {
        c[V[l]]++;
        c[V[r]]--;
        l++;
        r--;
    }
//
//	for(int i = 'a'; i <= 'z'; i++){
//		printf("%c : %d\n", i, c[i]);
//	}
//
    int pos = 0;
    for(char i = 'a'; i <= 'z'; i++) {
        if(c[i] == 0) continue;
        if(c[i] % 2 == 1) {
            int mid = (str.length() - 1) / 2;
            s[mid] = i; 
        }
        for(int j = 0; j < c[i] / 2; j++) {
            s[pos] = s[str.length() - 1 - pos] = i;
            pos++;
        }
    }

    for(int i = 0; i < str.length(); i++) {
        printf("%c", s[i]);
    }
}