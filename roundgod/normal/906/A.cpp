#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
char str[MAXN];
bool used[26];
bool included[26];
int main()
{
    scanf("%d",&n);
    getchar();
    bool f=false;
    int cnt=0;
    memset(used,false,sizeof(used));
    int num=26;
    for(int i=0;i<n;i++)
    {
        gets(str);
        int x=strlen(str);
        if(str[0]=='.')
        {
            for(int j=2;j<x;j++)
            {
                if(!used[str[j]-'a']) num--;
                used[str[j]-'a']=true;
            }
        }
        else if(str[0]=='!')
        {
            memset(included,false,sizeof(included));
            for(int j=2;j<x;j++)
                included[str[j]-'a']=true;
            for(int j=0;j<26;j++)
                if(!included[j])
                {
                    if(!used[j]) num--;
                    used[j]=true;
                }
            if(f) cnt++;
        }
        else
        {
            if(i!=n-1)
            {
                if(f) cnt++;
                if(!used[str[2]-'a']) num--;
                used[str[2]-'a']=true;
            }
        }
        if(num==1) f=true;
    }
    printf("%d\n",cnt);
    return 0;
}