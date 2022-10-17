#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    int x,y;
    ll num;
    while(q--){
        scanf("%d%d",&x,&y);
        num=(ll)(x-1)*n+y;
        if(n&1){
            if(num&1){
                cout<<((num+1)>>1)<<endl;
            }
            else{
                cout<<(num>>1)+(((ll)n*n+1)>>1)<<endl;
            }
        }
        else{
            if(x&1){
                if(y&1){
                    cout<<((num+1)>>1)<<endl;
                }
                else{
                    cout<<(num>>1)+((ll)n*n>>1)<<endl;
                }
            }
            else{
                if(y&1){
                    cout<<((ll)n*n>>1)+((num+1)>>1)<<endl;
                }
                else{
                    cout<<(num>>1)<<endl;
                }
            }
        }
    }
    return 0;
}