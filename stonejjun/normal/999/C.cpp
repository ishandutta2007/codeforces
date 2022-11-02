#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int c, d, q;
char a[600000];
int b[600000];
int main()
{
    scanf("%d %d",&c,&d);
    cin >> a;
    char check='a';
    for(q=0;q<c;q++)
        b[q]=1;
    while(d)
    {
        for(q=0; q<c; q++)
        {
            if(b[q]==1)
            {
                if(a[q]==check)
                {
                	d=d-1;
                    b[q]=0;
                    if(d==0)
					{
					 break;
					}
                }
            }
        }

        check++;
    }
    for(q=0;q<c;q++)
        if(b[q]==1) cout<<a[q];
}