#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN=100010;

int n;

char A[MAXN<<1];

int ans,cnt[26];

int main(){
    scanf("%d",&n);
    scanf("%s",A);
    n=strlen(A);
    for(int i=0;i<n;++i){
        if(A[i]>='a'&&A[i]<='z')++cnt[A[i]-'a'];
        else{
            if(!cnt[A[i]-'A'])++ans;
            else --cnt[A[i]-'A'];
        }
    }
    printf("%d\n",ans);
    return 0;
}