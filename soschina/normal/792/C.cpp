#include <cstdio>
using namespace std;
const int N = 1e5 + 2;

char s[N], t[N];

int sum, top;

bool solve(char *s){
    if(!*(s + 1)){
        if(sum == 0){
            puts(s);
            return true;
        }
        return false;
    }
    for (char *c = s + 1; *c; c++)
        if(sum == (*c - '0') % 3){
            *c = 0;
            printf("%s%s\n", s, c + 1);
            return true;
        }
    if(sum == (s[0] - '0') % 3 && s[1] != '0'){
        puts(s + 1);
        return true;
    }
    top = 0;
    t[top++] = s[0];
    int cnt = 0;
    for (char *c = s + 1; *c; c++){
        if((*c - '0') % 3 && cnt < 2)
            cnt++;
        else
            t[top++] = *c;
    }
    if(cnt == 2){
        t[top] = 0;
        puts(t);
        return true;
    }
    if(sum == (s[0] - '0') % 3){
        char *c = s + 1;
        do c++;
        while (*c == '0');
        if(!*c)
            putchar('0');
        else
            puts(c);
        return true;
    }
    return false;
}

int main(){
    scanf("%s", s);
    for (char *c = s; *c; c++)
        sum = (sum + *c - '0') % 3;
    if(sum == 0){
        puts(s);
        return 0;
    }
    if(!*(s + 1)){
        puts("-1");
        return 0;
    }
    if (!solve(s)){
        sum = (sum - (s[0] - '0') % 3 + 3) % 3;
        char *c = s + 1;
        bool has0 = s[1] == '0';
        while (*c == '0')
            c++;
        if(!*c){
            if(has0)
                putchar('0');
            else
                puts("-1");
        }
        else if(!solve(c)){
            if(has0)
                putchar('0');
            else
                puts("-1");
        }
    }
    return 0;
}