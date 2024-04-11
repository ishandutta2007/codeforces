#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n;
string str[100005];
int next[30], prev[30], in[30];
int used = 0, cnt = 0;

int val(char c) {
    return c - 'a';
}

string build(int ind) {
    used++;
    if(next[ind] == -1) return string(1, (char)(ind + 'a'));
    return string(1, (char)(ind + 'a')) + build(next[ind]);
}

int main() {
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < 30; i++) next[i] = -1, prev[i] = -1, in[i] = -1;
    for(int i = 0; i < n; i++) getline(cin, str[i]);
    for(int i = 0; i < n; i++) {
        string astr = str[i];
        for(int j = 0; j < astr.length(); j++) {
            if(in[val(astr[j])] == -1) {
                cnt++;
                in[val(astr[j])] = 1;
            }
            if(j == 0) continue;

            if((next[val(astr[j-1])] != -1 && next[val(astr[j-1])] != val(astr[j]))
                    || (prev[val(astr[j])] != -1 && prev[val(astr[j])] != val(astr[j-1]))) {
                return cout << "NO" << endl, 0;
            }
            next[val(astr[j-1])] = val(astr[j]);
            prev[val(astr[j])] = val(astr[j-1]);
        }
    }

    int strsize = 0;
    for(int i = 0; i < 26; i++) {
        if(in[i] == 1 && prev[i] == -1) {
            str[strsize++] = build(i);
        }
    }
    sort(str, str + strsize);
    if(used != cnt) return cout << "NO" << endl, 0;
    for(int i = 0; i < strsize; i++) {
        cout << str[i];
    }
}