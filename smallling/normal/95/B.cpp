#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,k,l,s,n,m,last;
char c[100005];
inline void print() {
    for (int i=1;i<=l;i++) printf("%c",c[i]);
}
inline void work(int o) {
    int s=0,S=0;
    if (o&1) {
        for (int i=1;i<=o+1;i++) if (i<=(o+1)/2) putchar('4');
        else putchar('7');
    }
    else {
        for (int i=1;i<=o;i++) if (c[i]=='4') s++;
        else S++;
        if (s==S) print();
        else if (s>S) {
            int gt=s-o/2;
            for (int i=o;i;i--) if (c[i]=='4'&&gt) c[i]='7',gt--;
            print();
        }
        else {
            if (!s) {
                for (int i=1;i<=o+2;i++) if (i<=(o+2)/2) putchar('4');
                else putchar('7');
                return ;
            }
            else {
                int i;
                for (i=o;i;i--) if (c[i]=='4'&&o-i+s-1>=o/2) break;
                else if (c[i]=='4') s--;
                if (i) {
                    s--;
                    c[i]='7';
                    int gt=o/2-(s);
                    i=i+1;
                    while (gt) {
                        c[i]='4'; gt--; i++;
                    }
                    for (i=i+1;i<=o;i++) c[i]='7';
                    print();
                }
                else {
                    for (int i=1;i<=o+2;i++) if (i<=(o+2)/2) putchar('4');
                    else putchar('7');
                }
            }
        }
    }
}
            
int main() {
    scanf("%s",c+1);
    l=strlen(c+1);
    for (i=1;i<=l;i++) {
        if (c[i]!='4'&&c[i]!='7') break;
        if (c[i]=='4') last=i;
    }
    if (i>l) return work(l),0;
    if (c[i]>='7') {
        if (last) {
            c[last]='7';
            for (i=last+1;i<=l;i++) c[i]='4';
        }
        else {
            for (i=1;i<=l+1;i++) c[i]='4'; l++;
        }
    }
    else if (c[i]>='4') {
        c[i]='7'; for (i=i+1;i<=l;i++) c[i]='4'; //print();
    }
    else {
        c[i]='4'; for (i=i+1;i<=l;i++) c[i]='4';
    }
    work(l);
}