#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2002;

int t, n;
char s[N];
int dp[N][N];

int solve(int l, int r){
    if(l > r)
        return 1;
    if(r - l == 1)
        return s[l] == s[r];
    if(dp[l][r] != -1)
        return dp[l][r];
    int sell = 0;
    int selr = 0;
    if(s[l] == s[l + 1])
        sell = max(sell, solve(l + 2, r));
    else if(s[l] < s[l + 1]){
        int res = solve(l + 2, r);
        if(res != 1)
            sell = max(sell, res);
        else
            sell = max(sell, 0);
    }
    else{
        int res = solve(l + 2, r);
        if(res != 1)
            sell = max(sell, res);
        else
            sell = max(sell, 2);
    }
    if(s[l] == s[r])
        sell = max(sell, solve(l + 1, r - 1));
    else if(s[l] < s[r]){
        int res = solve(l + 1, r - 1);
        if(res != 1)
            sell = max(sell, res);
        else
            sell = max(sell, 0);
    }
    else{
        int res = solve(l + 1, r - 1);
        if(res != 1)
            sell = max(sell, res);
        else
            sell = max(sell, 2);
    }
    if(s[r] == s[r - 1])
        selr = max(selr, solve(l, r - 2));
    else if(s[r] < s[r - 1]){
        int res = solve(l, r - 2);
        if(res != 1)
            selr = max(selr, res);
        else
            selr = max(selr, 0);
    }
    else{
        int res = solve(l, r - 2);
        if(res != 1)
            selr = max(selr, res);
        else
            selr = max(selr, 2);
    }
    if(s[r] == s[l])
        selr = max(selr, solve(l + 1, r - 1));
    else if(s[r] < s[l]){
        int res = solve(l + 1, r - 1);
        if(res != 1)
            selr = max(selr, res);
        else
            selr = max(selr, 0);
    }
    else{
        int res = solve(l + 1, r - 1);
        if(res != 1)
            selr = max(selr, res);
        else
            selr = max(selr, 2);
    }
    return dp[l][r] = min(sell, selr);
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for (int i = 1; i <= n; i++)
            memset(dp[i] + 1, -1, sizeof(int) * n);
        switch(solve(1, n)){
            case 0:
                puts("Alice");
                break;
            case 1:
                puts("Draw");
                break;
            case 2:
                puts("Bob");
                break;
        }
    }
    return 0;
}