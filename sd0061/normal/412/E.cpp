#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
typedef long long LL;
using namespace std;
#define N 1000005

LL ans;
int n;
char s[N];

void cal(int l , int k , int r) {
    LL L = 0 , R = 0 ; int i , j;
    for (i = k - 1 ; i >= l ; -- i) {
        if (s[i] == '.')
            break;
        if (isalpha(s[i]))
            ++ L;
    }
    ++ k , j = 0;
    while (isalnum(s[k]))
        ++ k , ++ j;
    if (s[k] == '.' && j) {
        for (i = k + 1 ; i <= r ; ++ i) {
            if (!isalpha(s[i]))
                break;
            ++ R;
        }
    }
    ans += L * R;
}

void work()
{
    int i;
    vector<int> A;
    scanf("%s" , s + 1);
    n = strlen(s + 1);
    A.push_back(0);
    for (i = 1 ; i <= n ; ++ i)
        if (s[i] == '@')
            A.push_back(i);
    A.push_back(n + 1);
    for (i = 1 ; i + 1 < A.size() ; ++ i)
        cal(A[i - 1] + 1 , A[i] , A[i + 1] - 1);
    cout << ans << endl;
}

int main()
{
    work();
    return 0;
}