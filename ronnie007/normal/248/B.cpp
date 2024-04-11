#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;


int n;
vector <int> ans;

void input();
void solve();
int div();


int main()
    {
    input();
    solve();
    return 0;
    }



void input()
    {
    scanf("%d",&n);
    int i;
    ans.clear();
    ans.push_back(1);
    for(i=1;i<n;i++)
        {
        ans.push_back(0);
        }
    }


void solve()
    {
    int i;
    int k;
    int pr;
    if(n<3)
        {
        printf("-1\n");
        return ;
        }
    while(1)
        {
        if(div()==0)
            {
            for(i=0;i<n;i++)
                {
                printf("%d",ans[i]);
                }
            return ;
            }
        ans[n-1]++;
        k=n-1;
        pr=0;
        while(k>=0)
            {
            ans[k]+=pr;
            if(ans[k]<10)break;
            pr=ans[k]/10;
            ans[k]=ans[k]%10;
            k--;
            }
        }

    }



int div()
    {
    int i;
         //   for(i=0;i<n;i++)
          //      {
       //         printf("%d",ans[i]);
      //          }
    //system("pause");
    int ost=0;
    for(i=0;i<n;i++)
        {
        ost=ost*10+ans[i];
        ost=ost%210;
        }
    ost=ost%210;
    if(ost==0)return 0;
    return 1;
    }