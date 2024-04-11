#include <iostream>
using namespace std;
typedef long long LL;
int k,x,n,m;
// a=0, c=1, x=2
LL f[52];
char getc(int state) {
    if(state == 0) return 'A';
    if(state == 1) return 'C';
    return 'X';
}
char s1[102],s2[102];
bool Gen(int a1,int a2,int cnt, char * s,int n) {
    s[1]=getc(a1), s[n]=getc(a2);
    if(n==1 && a1!=a2) return false;
    if(n==2) {
        if(cnt==0 && s[1]=='A' && s[2]=='C') return false;
        if(cnt==1 && !(s[1]=='A'&& s[2]=='C')) return false;
        if(cnt>=2)return false;
        return true;
    }
    int now=0;
    for(int i=2;i<n;i++){
        if(now==cnt) {
            s[i]='X'; continue;
        }
        if(s[i-1]=='A') {
            s[i]='C'; now++;
        } else {
            s[i]='A';
        }
    }
    if(s[n-1]=='A'&&s[n]=='C') now++;
    if(now==cnt) return 1;
    return 0;
} 

void solve(int a1,int a2,int b1,int b2) {
    for(int i=0;i<=50;i++){
        for(int j=0;j<=50;j++){
            f[1]=i, f[2]=j;
            f[3]=i+j + ((a2==0&&b1==1)?1:0);
            bool buzhongyong = 0;
            for(int pos=4;pos<=k;pos++){
                f[pos]=f[pos-1]+f[pos-2];
                if(pos%2==0 && b2==0 && a1==1)f[pos]++;
                if(pos%2==1 && b2==0 && b1==1)f[pos]++;
                if(f[pos]>x) {
                    buzhongyong=1;
                }
            }
            if(!buzhongyong) {
                if(f[k] == x) {
                    bool ok1=Gen(a1,a2, i,s1,n);
                    bool ok2=Gen(b1,b2, j,s2,m);
                    if(ok1&&ok2) {
                        //printf("i=%d, j=%d (%d %d)(%d %d)\n", i,j,a1,a2,b1,b2);
                        printf("%s\n%s\n", s1+1,s2+1);
                        exit(0);
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d",&k,&x,&n,&m);
    for(int a1=0;a1<3;a1++)for(int a2=0;a2<3;a2++)
    for(int b1=0;b1<3;b1++)for(int b2=0;b2<3;b2++) {
        solve(a1,a2,b1,b2);
    }
    printf("Happy new year!\n");
}