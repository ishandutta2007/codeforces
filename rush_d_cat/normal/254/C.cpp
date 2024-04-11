#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100000 + 10;
char s[2][N];
int c[2][30],p[30],done,ans,n;
bool chk(int pos,int ch) {
    //printf("chk %d %d\n", pos,ch);
    c[0][s[0][pos]-'A']--;
    c[0][ch] ++;
    done += (s[0][pos] != ch + 'A') ? 1 : 0; p[ch] ++;

    int sum=0, ok=1;
    for(int i=0;i<26;i++){
        sum+=abs(c[0][i]-c[1][i]);
        if(p[i] > c[1][i]) ok = 0;
    }   
    ok &= (done + sum/2 == ans);
    //printf("done=%d, sum=%d, %d\n", done, sum,ok);
    c[0][s[0][pos]-'A']++;
    c[0][ch] --;
    done -= (s[0][pos] != ch + 'A') ? 1 : 0; p[ch] --;
    if (n - pos  < sum/2) return 0;
    return ok;
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%s%s",s[0]+1,s[1]+1);
    n=strlen(s[0]+1);
    for(int j=0;j<2;j++) for(int i=1;i<=n;i++) c[j][s[j][i] - 'A'] ++;
    int sum=0;
    for(int i=0;i<26;i++){
        sum+=abs(c[0][i]-c[1][i]);
    }   
    printf("%d\n", sum/2); ans=sum/2;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<26;j++){
            if(chk(i,j)) {
                c[0][s[0][i]-'A'] --;
                c[0][j] ++;
                if(s[0][i] != j+'A')
                    done++;
                p[j] ++;
                printf("%c", 'A'+j);
                break;
            }
        }
    }
}