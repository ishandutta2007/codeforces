#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
typedef long long LL;
#define vint vector<int>
using namespace std;
#pragma comment(linker, "/STACK:167177216")
int main()
{
    LL a,b;
    cin >> a >> b;
    LL k[19];
    int t = 0;
    k[0] = 1;
    for(int i = 1;i < 19;++i)
        k[i] = k[i - 1] * 10;
    while((a % 10 + 1) * k[t] <= b && a > 0)
    {
        if(a % 10 == 9)
        {
            a /= 10;
            t++;
            continue;
        }
        b -= (a % 10 + 1) * k[t];   
        a -= (a % 10 + 1);
        a /= 10;
        t++;
    }
    if(a != 0)
        cout << a;
    for(int i = 0;i < t;++i)
        cout << 9;
    return 0;
}