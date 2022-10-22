#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
string A , B;
void work()
{
    cin >> A >> B;
    int cnt = 0;
    for (int i = 0 ; i < A.size() ; i += 2) {
        if (A[i] == B[i]) continue;
        if (A[i] == '[') {
            if (B[i] == '8')
                -- cnt;
            else
                ++ cnt;
        }
        if (A[i] == '(') {
            if (B[i] == '[')
                -- cnt;
            else
                ++ cnt;
        }
        if (A[i] == '8') {
            if (B[i] == '(')
                -- cnt;
            else
                ++ cnt;
        }
    }
    if (cnt > 0) puts("TEAM 1 WINS");
    if (cnt == 0) puts("TIE");
    if (cnt < 0) puts("TEAM 2 WINS");
}


int main()
{
        work();
    return 0;
}