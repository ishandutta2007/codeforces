#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
    int n, i, j;
    char cha[1010];
    cin>>cha;
    n=strlen(cha);
    for(i=0;i<n;i++)
    {
        if(cha[i]=='n') continue;
        else if(cha[i]!='e'&&cha[i]!='i'&&cha[i]!='a'&&cha[i]!='o'&&cha[i]!='u')
        {
            if(cha[i+1]=='e'||cha[i+1]=='i'||cha[i+1]=='a'||cha[i+1]=='o'||cha[i+1]=='u')
                continue;
            else
            {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
}