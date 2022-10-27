#include <iostream>
#include <cstring>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;
int n; LL cnt[30]; int has[30]; LL now[30];
char s[N];

void update() {
    bool allsam=1;
    for(int i=1;s[i];i++) {
        if(s[i]!=s[1]) allsam = 0;
    }
    int len = strlen(s+1);

    for(int i=0;i<26;i++) now[i]=0;
    LL combo=0,pos;
    for(int i=1;s[i];i=pos){
        pos=i; combo=0;
        while(pos<=len && s[pos]==s[i]) pos++, combo++;
        now[s[i]-'a'] = max(now[s[i]-'a'], combo);

        //printf("ch = %c, combo = %d\n",s[i], combo);
    }

    char pre=s[1];   int prelen=1;
    char suf=s[len]; int suflen=1;
    while(prelen <= len && s[prelen] == s[1]) prelen ++; prelen --;
    while(suflen <= len && s[len+1-suflen] == s[len]) suflen ++; suflen --;

    if (allsam == 0) {
        for(int i=0;i<26;i++){
            if(has[i] == 0) continue;
            if( (i+'a' != pre) && (i+'a' != suf) )
                cnt[i]=has[i]?1:0;
            else if ((i+'a' == pre) && (i+'a' == suf)) 
                cnt[i]=prelen+suflen+1;
            else if(i+'a'==pre)
                cnt[i]=prelen+1;
            else if(i+'a'==suf)
                cnt[i]=suflen+1;
        }
    } else {
        for(int i=0;i<26;i++){
            if(has[i] == 0) continue;
            if(i+'a' == pre)
                cnt[i] = cnt[i] + (cnt[i]+1) * len;
            else
                cnt[i]=has[i]?1:0;
        }
    }
    for(int i=0;i<26;i++) cnt[i]=max(cnt[i],now[i]);
    for(int i=1;s[i];i++) has[s[i]-'a']=1;
}
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%s", s+1);
        update();
        /*
        for(int j=0;j<26;j++){
            if(cnt[j]) printf("%d(%c) ", cnt[j],'a'+j);
        } printf("\n");
        */
    }
    LL ans=0; for(int i=0;i<26;i++) ans=max(ans,cnt[i]);
    cout << ans << endl;
}