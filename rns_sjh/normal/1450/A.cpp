#include<bits/stdc++.h>
using namespace std;

int t, n;
string s;

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d", &n);
        cin >> s;
        int k = 0;
        for(char c : s) {
            if(c != 't') printf("%c", c);
            else k ++;
        }
        while(k --) printf("t");
        puts("");
    }
}