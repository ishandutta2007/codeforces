#include<bits/stdc++.h>
using namespace std;
map<long long, int> S;
main()
{
    for(long long i=0; i<=1000000; i++)
        S[i*i*i]=i;
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        long long A=a,B=b;
        long long c=(A*B);
        if(S.find(c)==S.end() || a%S[c]!=0 || b%S[c]!=0)
             printf("No\n");
        else 
             printf("Yes\n");
        
    }
}