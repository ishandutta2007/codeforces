#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N=200000+10;
typedef long long LL;
int t;
char s[N];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%s",s);
        int c[10]={0};
        for(int i=0;s[i];i++)c[s[i]-'0']++;
        int n=strlen(s);
        if(n==1 && c[0]==1) {
            printf("red\n"); continue;
        }
        if(c[0]==0) {
            printf("cyan\n");
        } else {
            bool ok=0;
            int pos=0; for(int i=0;s[i];i++) if(s[i]=='0') pos=i;
            for(int i=0;s[i];i++){
                if(i==pos) continue;
                int sum=0;
                for(int j=0;s[j];j++){
                    if(j==pos) continue;
                    if(i==j) sum += (s[j]-'0');
                    else sum += 4 * (s[j]-'0');
                }
                if(sum%6==0) {
                    //printf("i=%d\n", i);
                    ok=1;
                }
            }
            printf("%s\n", ok?"red":"cyan");
        }
    }
}