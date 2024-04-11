#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
	long long int start=1;
	double real;
    long long int k, k0, j,tra=0;
    cin>>k;
    k0=k;
    if(k<=999) start=1;
    else
    {
        real=k*0.039259424579;
        start=real;
    }
    int ans=0;
    for(j=start; j<k0; j++)
    {
        tra=0;
        k=k0;
        while(k>0)
        {
            if(k<j)
            {
                tra+=k;
                break;
            }
            else tra+=j;
            k-=j;
            k=k-k/10;
        }
        if(tra*2>=k0) break;
    }
    printf("%lld", j);
}