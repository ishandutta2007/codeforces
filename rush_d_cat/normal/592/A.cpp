#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef __int64 ll;
char map[2000][2000];
int main()
{
    for(int i=0;i<8;i++) scanf("%s",map[i]);
    int len = 8,cnt = 8;
    int m1=10,m2=10;
    for(int i=0;i<len;i++)//i  j 
    {
        for(int j=0;j<cnt;j++)
        {
            if(map[j][i]=='B') break;
            if(map[j][i]=='W') m1=min(m1,j);
        }
        for(int j=cnt-1;j>=0;j--)
        {
            if(map[j][i]=='W') break;
            if(map[j][i]=='B') m2=min(m2,cnt-j-1);
        }
    }
    putchar((m1<=m2)?'A':'B');
    return 0;
}