#include<bits/stdc++.h>
using namespace std;

char s[100010];

int main() {
    int n, z = 0, o = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for(int i = 0; i < n; i ++) if(s[i] == 'z') z ++;
    for(int i = 0; i < n; i ++) if(s[i] == 'n') o ++;
    while(o --) printf("1 ");
    while(z --) printf("0 ");
}