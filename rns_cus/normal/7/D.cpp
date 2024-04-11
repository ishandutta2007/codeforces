#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define M 5100000
int z[2 * M];
char s[2 * M], t[2 * M];
int ans[2 * M];
void  doZ(int L, char *s, int *z){
    int r=1, l=1;
    for(; r<L and s[r]==s[r-1]; r++);
     z[1]=r-1;
    for(int i=2; i<L; i++){
        if(r>i and z[i-l]<r-i)
           z[i]=z[i-l];
        else {
            l=i;
            r=max(r,i);
            for(; r<L and s[r]==s[r-i]; r++);
               z[i]=r-i;
        }
    }
}
int main(){
    //freopen("D.in","r",stdin);
    while(scanf("%s", s) == 1){
        int len = strlen(s);
        strcpy(t,s);
        t[len] = 0;
        strrev(t);
        strcat(s, "&");
        strcat(s,t);
        int L = strlen(s);
        doZ(L, s, z);
        int Ans = 1;
        ans[0] = 1;
        for(int i = 1; i < len; i ++){
            ans[i] = 0;
            int x = z[len + len - i];
            if(x >= (i + 1) / 2)ans[i] = ans[(i - 1) / 2] + 1;
            Ans += ans[i];
        }
        printf("%d\n", Ans);
    }
    return 0;
}