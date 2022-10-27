#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;

const int N = 100000+10;
char s[N];
int n, pre[N], suf[N];
vector<char> v[N];
vector<char> sol;

LL cac() {
    LL ans = 0;
    LL ch = 0;
    for (int i = 0; i < sol.size(); i ++) ch += (sol[i] == 'h');
    for (int i = 0; i < sol.size(); i ++) {
        if (sol[i] == 's') ans += ch;
        if (sol[i] == 'h') ch = ch - 1;
    }
    return ans;
}

bool cmp(vector<char> A, vector<char> B) 
{
    LL ans1, ans2;
    
    sol.clear();
    for (int i = 0; i < A.size(); i ++) sol.push_back(A[i]);
    for (int i = 0; i < B.size(); i ++) sol.push_back(B[i]);
    ans1 = cac();
    
    sol.clear();
    for (int i = 0; i < B.size(); i ++) sol.push_back(B[i]);
    for (int i = 0; i < A.size(); i ++) sol.push_back(A[i]);
    ans2 = cac();
    
    return ans1 > ans2;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", s+1);
        int len = strlen(s+1);
        for (int j = 1; j <= len; j ++) {
            v[i].push_back(s[j]);
        }
    }
    sort(v+1, v+1+n, cmp);
    sol.clear();
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < v[i].size(); j ++) {
            sol.push_back(v[i][j]);
        }
    }
    printf("%lld\n", cac());
}