#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 200000+10;
typedef long long LL;
int a,b;
bool vis[1000000+10];
vector<int> va,vb;
int main() {
    cin>>a>>b;
    bool flag=0;
    if(a>b) swap(a,b), flag=1;

    int x=1;
    while(x*(x+1)/2 < a) x ++;

    for(int i=x;i>=1;i--) {
        if(a>=i) {
            va.push_back(i);a-=i;vis[i]=1;
        }
    }

    int s=0;
    for(int i=1;i<=1000000;i++){
        if(vis[i]==0){
            if(s+i<=b) {
                s+=i; vb.push_back(i);
            } else {
                break;
            }
        }
    }
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    if(!flag) {
        printf("%d\n", va.size());
        for(auto x: va) printf("%d ", x); printf("\n");
        printf("%d\n", vb.size());
        for(auto x: vb) printf("%d ", x); printf("\n");
    }else{
        printf("%d\n", vb.size());
        for(auto x: vb) printf("%d ", x); printf("\n");
        printf("%d\n", va.size());
        for(auto x: va) printf("%d ", x); printf("\n");
    }
}