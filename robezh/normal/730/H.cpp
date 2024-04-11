#include<cstdio>
#include<iostream>
#include<string>
#include<set>
using namespace std;

string str[105];
int ind[105];
char c[105];
int len;

int match(string k, char s[]) {
    if(k.length() != len) return false;
    for(int i = 0; i < len; i++) {
        if(s[i] != '?' && k[i] != s[i]) return false;
    }
    return true;
}

int main() {
    int n,m;
    fill(c, c + 105, '*');
    scanf("%d%d", &n, &m);
    getchar();
    for(int i = 0; i < n; i++) {
        getline(cin, str[i]);
    }
    for(int i = 0; i < m; i++) scanf("%d", &ind[i]), ind[i]--;
    len = -1;
    for(int t = 0; t < m; t++) {
        int i = ind[t];
        if(len == -1) len = str[i].length();
        else if(len != str[i].length()) return !printf("No");

        for(int j = 0; j < len; j++) {
            string s = str[i];
            if(c[j] == '*') c[j] = s[j];
            else if(s[j] != c[j]) c[j] = '?';
        }
    }
    bool del[105];
    
    fill(del, del+105, false);
    for(int i = 0; i < m; i++) del[ind[i]] = true;
    for(int j = 0; j < n; j++) {
        if(!del[j] && match(str[j], c)){
        	return !printf("No\n");
		}
    }
    printf("Yes\n");
    for(int i = 0; i < len; i++) {
        printf("%c", c[i]);
    }
}