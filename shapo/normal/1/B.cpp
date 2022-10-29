#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

#define maxlen 200

using namespace std;

int n;
char s[maxlen], res[maxlen];

bool digit(const char &c){return('0' <= c && c <= '9');}

int add(const char &x, int &len, char *s){
    s[len] = x; ++len; s[len] = 0; return 0;
}

int main(){
    scanf("%d", &n);
    for(int j = 1; j <= n; ++j){
        scanf(" %s", s);
        int len = strlen(s), ind = 0, curn = 0, curm = 0, rlen = 0, i;
        if(s[0] == 'R'){
            if(digit(s[1])){
                i = 1;
                while(i < len && digit(s[i]))++i;
                if(i == len)ind = 1;else ind = 2;
            }
            else ind = 1;
        }
        else ind = 1;
        if(ind == 1){
            int i = 0;
            while(!digit(s[i])){
                curn = curn * 26 + int(s[i] - 'A' + 1);
                ++i;
            }
            while(i < len){
                curm = curm * 10 + int(s[i] - '0');
                ++i;
            }
            printf("R%d", curm);
            printf("C%d\n", curn);
        }
        else{
            int i = 1;
            while(s[i] != 'C'){
                curn = curn * 10 + int(s[i] - '0');
                ++i;
            }
            ++i;
            while(i < len){curm = curm * 10 + int(s[i] - '0'); ++i;}
            while(curm){
                add(char((curm - 1) % 26 + int('A')), rlen, res);
                curm = (curm - 1) / 26;
            }
            //++res[0];
            for(int ii = rlen - 1; ii >= 0; --ii)printf("%c", res[ii]);
            printf("%d\n", curn);
        }
    }
    return 0;
}