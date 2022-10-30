#include<stdio.h>
#include<string.h>

char s[20];
int dd, yy, mm, x[5];
const int m_day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool correct(int d, int m, int y){
    if(m > 12) return 0;
    if((m!=2 or y%4) and d > m_day[m]) return 0;
    if(m==2 and y%4==0 and d > 29) return 0;
    return 1;
}

bool old(int d, int m, int y){  return yy > y+18 ? 1 : yy < y+18 ? 0: mm!=m ? mm > m : dd >= d ; }

int main(){
    gets(s);
    dd = s[0] * 10 + s[1] - 528 ; mm = s[3] * 10 + s[4] - 528 ; yy = s[6] * 10 + s[7] - 528 ;
    gets(s);
    for(int i = 0; i < 3; i ++) x[i] = s[3*i] * 10 + s[3*i+1] - 528 ;
    int t = 0;
    bool OK = 0;
    for(int i = 0; i < 3; i ++)for(int j = 0; j < 3; j ++) if(i!=j){
        t = 3 - i - j;
        if(correct(x[i], x[j], x[t]) and old (x[i], x[j], x[t])){ OK = 1; break; }
    }
    if(OK) puts("YES");
    else puts("NO");
}