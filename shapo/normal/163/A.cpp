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

#define maxns 5010

using namespace std;

const long long osn = 1000000007;
char s[maxns], t[maxns];
int res[maxns][maxns], sum[maxns][maxns], to_go;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf(" %s %s", s, t);
    int l1 = strlen(s), l2 = strlen(t);
    res[0][0] = sum[0][0] = 1;
    for(int i = 1; i < maxns; ++i)sum[0][i] = sum[0][i - 1] + res[0][i];
    to_go = 0;

    for(int i = 1; i <= l1; ++i){
        res[i][0] = sum[i][0] = 1;
        for(int j = 1; j <= l2; ++j){
            if(s[i - 1] == t[j - 1])res[i][j] = sum[i - 1][j - 1];
            sum[i][j] = (sum[i][j - 1] + res[i][j]) % osn;
            to_go = (to_go + res[i][j]) % osn;
            //printf("res[%d][%d] = %d\n", i, j, res[i][j]);
        }
    }

    printf("%d\n", to_go);

    return 0;
}