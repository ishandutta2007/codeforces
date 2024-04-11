#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN=100010;

inline bool cmp(int x,int y){return x>y;}

int n,len[MAXN];

typedef long long ll;

ll ans;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",len+i);
    sort(len+1,len+1+n,cmp);
    int last=0,cur=0;
    for(int i=1;i<n;){
        if(len[i]==len[i+1]){
            cur=len[i];
            i+=2;
        }
        else if(len[i]-1==len[i+1]){
            cur=len[i+1];
            i+=2;
        }
        else ++i;
        if(cur){
            if(last){
                ans+=(ll)last*cur;
                last=cur=0;
            }
            else{
                last=cur;
                cur=0;
            }
        }
    }
    cout<<ans;
    return 0;
}