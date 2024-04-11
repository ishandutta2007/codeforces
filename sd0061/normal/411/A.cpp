#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cctype>
using namespace std;

#define N 105

char s[N];

void work() {
    scanf("%s" , s);
    if (strlen(s) < 5) {
        puts("Too weak");
        return;
    }
    int i;
    for (i = 0 ; s[i] ; ++ i)
        if (islower(s[i]))
            break;
    if (!s[i]) {
        puts("Too weak");
        return;
    }
    for (i = 0 ; s[i] ; ++ i)
        if (isdigit(s[i]))
            break;
    if (!s[i]) {
        puts("Too weak");
        return;
    }
    for (i = 0 ; s[i] ; ++ i)
        if (isupper(s[i]))
            break;
    if (!s[i]) {
        puts("Too weak");
        return;
    }
    puts("Correct");
}

int main(){
    work();
    return 0;
}