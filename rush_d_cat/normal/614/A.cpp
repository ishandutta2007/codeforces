#include<iostream>
using namespace std;
int main()
{
    __int64 l,r,k;cin>>l>>r>>k;
    __int64 t=1;
    bool ok=0;
    while(true)
    {
        if(t<=r&&t>=l){
            printf("%I64d ",t);
            ok=true;
        }
        if(t>r||t>1e18/k){
             if(!ok) printf("-1");
             printf("\n");break;
        }
        t*=k;
    }
    return 0;
}