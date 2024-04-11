#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18;
const ll INF=1LL<<55;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    for(int k=0;k<Q;k++){
        int b,w;cin>>b>>w;
        if(b>w){
            if(b<=3*w+1){
                printf("YES\n");
                for(int i=1;i<=2*w+1;i++){
                    printf("2 %d\n",i);
                }
                b-=(w+1);
                for(int i=1;i<=min(b,w);i++){
                    printf("1 %d\n",2*i);
                }
                b-=w;
                for(int i=1;i<=b;i++){
                    printf("3 %d\n",2*i);
                }
            }else printf("NO\n");
        }else if(b<w){
            if(w<=3*b+1){
                printf("YES\n");
                for(int i=1;i<=2*b+1;i++){
                    printf("2 %d\n",i+1);
                }
                w-=(b+1);
                for(int i=1;i<=min(b,w);i++){
                    printf("1 %d\n",2*i+1);
                }
                w-=b;
                for(int i=1;i<=w;i++){
                    printf("3 %d\n",2*i+1);
                }
            }else printf("NO\n");
        }else{
            printf("YES\n");
            for(int i=1;i<=b+w;i++){
                printf("1 %d\n",i);
            }
        }
    }
    
}