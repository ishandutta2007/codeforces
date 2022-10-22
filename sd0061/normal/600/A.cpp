#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <set>
using namespace std;
typedef long long LL;
const int N = 1000005;

char str[N];
vector<string> V[2];
void work() {
    scanf("%s" , str);
    int len = strlen(str);
    str[len ++] = ',';
    string S = "";
    for (int i = 0 ; i < len ; ++ i) {
        if (str[i] == ',' || str[i] == ';') {
            int flag = 1;
            for (int j = 0 ; j < S.size() ; ++ j) {
                if (!isdigit(S[j]))
                    flag = 0;
            }
            if (S.empty() || (S.size() > 1 && S[0] == '0'))
                flag = 0;
            V[!flag].push_back(S);
            S = "";
        } else {
            S += str[i];
        }
    }
    if (V[0].empty()) {
        puts("-");
    } else {
        printf("\"");
        bool f = 0;
        for (auto &s : V[0]) {
            if (f) putchar(',');f = 1;
            printf("%s" , s.c_str());
        }
        printf("\"");
        puts("");
    }
    if (V[1].empty()) {
        puts("-");
    } else {
        printf("\"");
        bool f = 0;
        for (auto &s : V[1]) {
            if (f) putchar(',');f = 1;
            printf("%s" , s.c_str());
        }
        printf("\"");
        puts("");
    } 
}

int main() {
    work();
    return 0;
}