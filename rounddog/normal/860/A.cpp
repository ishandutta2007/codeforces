#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 1e9
#define maxn 500050

using namespace std;

char s[maxn];
int n;
bool f[500];

int main()
{
    scanf("%s",s);n=strlen(s);
    memset(f,true,sizeof(f));
    f[97]=f[101]=f[105]=f[111]=f[117]=false;
    int j=0;
    bool flag=true;
    for (int i=0;i<n;i++)
    {
        if (f[s[i]])
        {
            j++;
            if(j>1&&s[i]!=s[i-1]) flag=false;
        }
        else
        {
            j=0;
            flag=true;
        }
        if (j>=3&&!flag) printf(" "),j=1,flag=true;
        printf("%c",s[i]);
    }
    printf("\n");
}