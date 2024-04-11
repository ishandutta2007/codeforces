/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-28 17:37:17
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
bool is_pal(string x)
{
    int len=x.size();
    for(int i=0;i<len/2;i++)
        if(x[i]!=x[len-1-i]) return false;
    return true;
}
string str;
int main()
{
    cin>>str;
    int len=str.size();
    for(int i=len;i>=1;i--)
    {
        for(int j=0;j+i<=len;j++)
        {
            if(!is_pal(str.substr(j,i)))
            {
                printf("%d\n",i);
                return 0;
            }
        }
    }
    puts("0");
    return 0;
}