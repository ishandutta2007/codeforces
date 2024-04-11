#include <bits/stdc++.h>
using namespace std;

char s[1000];
int pu_cou, mi_cou;
int n;
int maxn, minn;
int pu[1000], mi[1000], sum;

int main(){
    gets(s);
    pu_cou = 1; mi_cou = 0;
    for(int i=0; i<strlen(s); i++){
        if(s[i]=='+') pu_cou++;
        if(s[i]=='-') mi_cou++;
        if(s[i]=='='){
            n = atoi(s+i+1);
        }
    }
    maxn = n*pu_cou - mi_cou;
    minn = pu_cou - n*mi_cou;
    if(n<minn || n>maxn) {puts("Impossible"); return 0;}

    for(int i=0; i<mi_cou; i++) mi[i]=n;
    for(int i=0; i<pu_cou; i++) pu[i]=1;
    sum = minn;

    int mipo=0, pupo=0;
    while(sum<n && mipo<mi_cou){
        mi[mipo] = max(1, sum);
        sum += n - mi[mipo++];
    }
    while(sum<n && pupo<pu_cou){
        pu[pupo] = min(n, 1+n-sum);
        sum += pu[pupo++] - 1;
    }

    if(sum!=n) {puts("Impossible"); return 0;}

    puts("Possible");
    pupo=1; mipo=0; printf("%d", pu[0]);
    for(int i=0; i<strlen(s); i++){
        if(s[i]=='+'){
            printf(" + %d", pu[pupo++]);
        }
        if(s[i]=='-'){
            printf(" - %d", mi[mipo++]);
        }
        if(s[i]=='='){
            printf(" = %d\n", n);
        }
    }
}