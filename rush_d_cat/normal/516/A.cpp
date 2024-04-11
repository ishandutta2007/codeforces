#include <iostream>
#include <cstdio>
using namespace std;
char s[20];
int n, cnt[12];
int main()
{
    cin >> n;
    scanf("%s", s+1);
    for(int i=1;i<=n;i++)
    {
        cnt[s[i]-'0']++;
    }
    cnt[3] += cnt[4];
    cnt[2] += 2*cnt[4];
    cnt[3] += cnt[6];
    cnt[5] += cnt[6];
    cnt[2] += 3*cnt[8];
    cnt[7] += cnt[8];
    cnt[3] += cnt[9]*2;
    cnt[2] += cnt[9];
    cnt[7] += cnt[9];
    cnt[4] = 0, cnt[6] = 0, cnt[8] = 0, cnt[9] = 0;
    for(int i=9;i>=2;i--)
    {
        while(cnt[i])
        {
            cnt[i]--;
            printf("%d", i);
        }
    }
}
/*
vanishment the prefix of non-prime!
9! = 9*8*7*6*5*4*3*2*1
3! = 6
2! = 2
4 -> 322
6 -> 53
8 -> 7222
9 -> 7332

9 3*3*2*2*2*7!

*/