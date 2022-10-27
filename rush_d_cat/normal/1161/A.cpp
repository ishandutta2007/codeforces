#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int N=100000+10;
int n,k,a[N];
int pre[N],las[N];
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&a[i]);
        if(pre[a[i]]==0) pre[a[i]]=i;
        las[a[i]]=i;
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        if(pre[i]==0){
            ans++;
        } 
        if(i<n){
            if(pre[i] && las[i+1]) {
                int r=pre[i]-1;
                int l=las[i+1];
                if(r>=l) ans++;
            } else {
                ans++;
            }
        }
        if(i>1) {
            // i i i i-1 i-1
            if(pre[i] && las[i-1]) {
                int r=pre[i]-1;
                int l=las[i-1];
                if(r>=l) ans++;
            } else {
                ans++;                    
            }
        }        
    }
    cout<<ans<<endl;
}