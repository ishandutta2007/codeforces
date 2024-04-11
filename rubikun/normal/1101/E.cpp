#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    int N;cin>>N;
    int mini=0,maxi=0;
    for(int i=0;i<N;i++){
        char a;cin>>a;
        int h,w;scanf("%d %d",&h,&w);
        if(a=='+'){
            if(h>w) swap(h,w);
            mini=max(mini,h);
            maxi=max(maxi,w);
        }else{
            if(h>w) swap(h,w);
            if(mini<=h&&maxi<=w) printf("YES\n");
            else printf("NO\n");
        }
    }
}