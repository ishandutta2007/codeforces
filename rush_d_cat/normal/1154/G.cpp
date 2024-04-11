#include <iostream>
#include <vector>
using namespace std;
const int N=10000000+10;
typedef long long LL;
int n,a[N],c[N],v[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x); v[i]=x; a[x]=i; c[x]++;
    }
    LL ans=1e18;
    LL ans1,ans2;
    for(int i=1;i<=10000000;i++){
        LL p=-1,q=-1;
        int A=0,B=0;
        for(int j=i;j<=10000000;j+=i){
            if(a[j]){
                if(p==-1) p=j,A=a[j];
                else {
                    q=j,B=a[j]; break;
                }
            }
        }
        if(p>0&&q>0){
            if(p*q/i < ans){
                ans=p*q/i; 
                ans1=A, ans2=B;
            }
        }
    }
    int val=-1;
    for(int i=1;i<=10000000;i++){
        if(c[i]>=2) {
            val=i; break;
        }
    }
    if(val!=-1 && val<ans) {
        vector<int> ret;
        for(int i=1;i<=n;i++){
            if(v[i]==val){
                ret.push_back(i);
            }   
            if(ret.size()==2) break;
        }
        printf("%d %d\n", ret[0], ret[1]); return 0;
    }
    if(ans1>ans2) swap(ans1,ans2);
    cout<<ans1<<" "<<ans2<<endl;
}