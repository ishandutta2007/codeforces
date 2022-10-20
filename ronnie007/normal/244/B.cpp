#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<set>
using namespace std;


set <int> numbers;

int n;
int br=0;
int a[50];
long long num;
int len;
int x;
int y;



void input();
void gen(int t);
void check();


int main()
    {
    input();
    return 0;
    }


void input()
    {
    scanf("%d",&n);
    int i,j,z;
    for(i=0;i<10;i++)
        {
        for(j=i+1;j<10;j++)
            {
            for(z=1;z<=10;z++)
                {
                x=i;
                y=j;
                len=z;
                gen(1);
                }
            }
        }
    printf("%d\n",numbers.size()-1);
    }




void gen(int t)
    {
    if(t==len+1){check();return ;}
    a[t]=1;
    gen(t+1);
    a[t]=2;
    gen(t+1);
    }


void check()
    {
    num=0;
    int i;
    for(i=1;i<=len;i++)
        {
        if(a[i]==1)
            {
            num=num*10+x;
            }
        else
            {
            num=num*10+y;
            }
        }
    if(num<=n)
        {
        numbers.insert(num);
        }
    }