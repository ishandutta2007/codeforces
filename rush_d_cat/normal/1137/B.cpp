#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;

char s[N],t[N],res[N]; int nex[N];

void build() {
    nex[0]=nex[1]=0;
    int j=0;
    for(int i=1;s[i];i++) {
        while(j>0 && s[i]!=s[j]) j=nex[j];
        if(s[i]==s[j]) j++;
        nex[i+1] = j;
        //printf("nex[%d] = %d\n", i+1, j);
    }
}
int match(char * t) {
    int ans=0;
    int j=0; int len=strlen(s);
    for(int i=0;t[i];i++){
        while(j>0 && t[i]!=s[j]) j=nex[j];
        if(t[i]==s[j]) j++;
        if(j==len) ans++;
    }
    return ans;
}
int main() {
    scanf("%s%s",t,s);
    build(); 
    int len = strlen(s);
    int pos = nex[len];
    int n = strlen(t);

    int cnt[2] = {0};
    for(int i=0;i<n;i++) {
        if(t[i]=='1') cnt[1] ++; else cnt[0] ++;
    }   

    int need1[2] = {0}, need2[2] = {0};
    for(int i=0;i<len;i++) {
        if(s[i]=='1') need1[1] ++; else need1[0] ++;
    }
    for(int i=pos;i<len;i++) {
        if(s[i]=='1') need2[1] ++; else need2[0] ++;
    }

    if (len > n || need1[0] > cnt[0] || need1[1] > cnt[1]) {
        printf("%s\n", t); return 0;
    }

    for(int i=0;i<len;i++) 
        res[i] = s[i];
    int now = len;
    cnt[0] -= need1[0], cnt[1] -= need1[1];

    while(now < n) {
        if (cnt[0] >= need2[0] && cnt[1] >= need2[1]) {
            for(int i=pos;i<len;i++) {
                res[now++] = s[i];
            }
            cnt[0] -= need2[0]; cnt[1] -= need2[1];
        } else {
            while(cnt[1]) {
                res[now++] = '1'; cnt[1] --;
            }
            while(cnt[0]) {
                res[now++] = '0'; cnt[0] --;
            }
        }
    }
    printf("%s\n", res);
}