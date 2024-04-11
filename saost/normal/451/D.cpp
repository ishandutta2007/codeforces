#include <iostream>
#include <cstring>
using namespace std;
char s[100005];
int n;

pair<long long, long long> solve() {
    long long ansOdd = 0, ansEven = 0;
    long long cntOdd[2] = {0,0}, cntEven[2] = {0,0};
    for(int i=0; i<n; i++) {
        ansOdd++;
        int id = s[i] - 'a';
        if (i%2 == 0) {
            ansOdd += cntEven[id];
            ansEven += cntOdd[id];
            cntEven[id]++;
        }
        else  {
            ansOdd += cntOdd[id];
            ansEven += cntEven[id];
            cntOdd[id]++;
        }
    }
    return make_pair(ansEven, ansOdd);
}

int main()
{
    //freopen("gstring.inp","r",stdin);
    //freopen("gstring.out","w",stdout);
    scanf("%s", &s);
    n = strlen(s);
    pair<long long, long long> res = solve();
    cout << res.first << ' ' << res.second;
}