#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 3005;

char str[N];

void work() {
    scanf("%s" , str);
    set<char> h;
    int sum = 0;
    for (auto c : str)
        if (isalpha(c)) 
            h.insert(c);
        else if (c == '?')
            ++ sum;
    int p = 10 , c = h.size();
    LL res = 1;
    if (*str == '?')
        res *= 9 , -- sum;
    if (isalpha(*str))
        -- c , res *= 9 , -- p;
    for (int i = 1 ; i <= p ; ++ i)
        res *= i;
    for (int i = 1 ; i <= p - c ; ++ i)
        res /= i;
    cout << res ;
    while (sum --)
        cout << 0;
}

int main() {
    work();
    return 0;
}