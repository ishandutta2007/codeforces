#include<iostream>
#include<string>
using namespace std;
int used[10];
int main ()
{
    int i,j,k,x,br=0;
    cin>>x;
    j=x;
    while(x!=0)
    {
        used[x%10]++;
        x/=10;
    }
    x=j;
    if(x==1){cout<<1<<endl;return 0;}
    for(i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            k=i;
            while(k!=0)
            {
                if(used[k%10]!=0){br++;break;}
                k/=10;
            }
            k=x/i;
            if(k!=i)
            while(k!=0)
            {
                if(used[k%10]!=0){br++;break;}
                k/=10;
            }

        }
    }
    cout<<br<<endl;
    return 0;
}