#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

stack<char> st;
int arr[101010];
int main()
{
    ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y; //
    int ga=0,se=0;
    char z[101010];
    ll sum,ans;
    scanf("%s",&z);
    for(i=0;i<strlen(z);i++)
    {
        if(z[i]=='0')
        {
            if(ga==0)
            {
                ga++;
                printf("1 1\n");
            }
            else if(ga==1)
            {
                ga--;
                printf("3 1\n");
            }
        }
        else if(z[i]=='1')
        {
            if(se==0)
            {
                se++;
                printf("4 3\n");
            }
            else if(se==1)
            {
                se--;
                printf("4 1\n");
            }
        }
    }
}