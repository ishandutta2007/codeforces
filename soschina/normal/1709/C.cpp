#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e5 + 2;

int t, sum[N];
char s[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", s + 1);
        int cntl = 0, cntr = 0, cntq = 0;
        for (char *c = s + 1; *c; c++){
            if(*c == '(')
                cntl++;
            else if(*c == ')')
                cntr++;
            else
                cntq++;
        }
        int addl, addr;
        if(cntl < cntr){
            int diff = cntr - cntl;
            addr = (cntq - diff) / 2;
            addl = addr + diff;
        }
        else{
            int diff = cntl - cntr;
            addl = (cntq - diff) / 2;
            addr = addl + diff;
        }
        int l;
        for (l = 1; addl; l++){
            if(s[l] == '?'){
                s[l] = '(';
                addl--;
            }
            if (s[l] == '(')
                sum[l] = sum[l - 1] + 1;
            else
                sum[l] = sum[l - 1] - 1;
        }
        int r;
        for (r = strlen(s + 1); addr; r--)
            if(s[r] == '?')
                addr--;
        bool flag = sum[l - 2] == 0;
        for (int i = l; i <= r; i++){
            if(s[i] == '(')
                sum[i] = sum[i - 1] + 1;
            else
                sum[i] = sum[i - 1] - 1;
            if(sum[i] <= 1)
                flag = true;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}