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
bool b[10];
bool f(int t)
{
    while(t)
    {
        if(b[t % 10])
            return 1;
        t /= 10;
    }
    return 0;
}
int main()
{
    int a;
    cin >> a;
    if(a == 1)
    {
        cout << 1;
        return 0;
    }
    int t = a;
    while(t)
    {
        b[t % 10] = 1;
        t /= 10;
    }
    int ans = 0;
    for(int i = 1;i * i <= a;++i)
    {
        if(a % i == 0)
        {
            if(f(i))
            {
                ans++;
                if(i * i == a)
                    ans--;
            }
            if(f(a / i))
                    ans++;
        }
    }
    cout << ans;
    return 0;
}