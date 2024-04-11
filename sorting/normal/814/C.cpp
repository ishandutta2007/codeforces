#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int n,q,res[26][1501];
char c[1501],ch;

int main ()
{
    int i,p,j,j2,curr,j3;

    scanf("%d ",&n);
    for(i=0;i<n;i++)scanf("%c",&c[i]);

    for(i=0;i<n;i++)
    {
        p=(int)c[i]-'a';
    }

    for(i=0;i<26;i++)
    {
        curr=0;
        ch=(char)i+'a';
        for(j=1;j<=n;j++)
        {
            curr=j;
            for(j2=0;j2<curr;j2++)
            {
                if(c[j2]==ch)
                {
                    if(curr!=n)curr++;
                }
            }
            while(j2<n && c[j2]==ch)
            {
                curr++;
                j2++;
            }
            res[i][j]=curr;
            //cout<<curr<<endl;
            for(j2=1;j2<n;j2++)
            {
                if(c[j2-1]==ch)curr--;
                j3=j2+curr;
                if(j3>=n+1)curr--;
                while(j3<n && c[j3]==ch)
                {
                    curr++;
                    j3++;
                }
                if(curr>res[i][j])res[i][j]=curr;
            }
            //cout<<res[i][j]<<" "<<ch<<" "<<j<<endl;
        }
    }

    scanf("%d",&q);

    for(i=0;i<q;i++)
    {
        scanf("%d %c",&p,&ch);
        j3=(int)ch-'a';
        printf("%d\n",res[j3][p]);
    }

    return 0;
}