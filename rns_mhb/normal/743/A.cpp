#include<bits/stdc++.h>
using namespace std;

#define N 200020

int n, a, b;
char s[N];

int main(){
    scanf("%d %d %d", &n, &a, &b);
    scanf("%s", s);
    if(s[a-1] == s[b-1]) puts("0");
    else puts("1");
}