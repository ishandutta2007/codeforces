#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define N 510

int n, x, y, a[N], m;
pair <int, int>  b[N], c[N], d[N];
bool OK;

int main(){
    scanf("%d %d", &n, &m);
    int nn = n / 2;
    for(int i = 0; i < n; i ++){ scanf("%d %d", &x, &y); a[i] = x + y; }
    for(int i = 0; i < m; i ++){ scanf("%d", &x); b[i] = make_pair(x, i + 1); }
    sort(b, b + m);
    for(int i = 0; i < nn; i ++){
        c[i] = make_pair(fabs(a[2*i]-a[2*i+1]) + fabs(a[2*i]-a[(2*i+n-1)%n]), 2*i);
        d[i] = make_pair(fabs(a[2*i+1]-a[2*i]) + fabs(a[2*i+1]-a[(2*i+2)%n]), 2*i+1);
    }
    sort(c, c + nn);     sort(d, d + nn);
    memset(a, -1, sizeof a);
    OK = 1;
    for(int i = 0, j = 0; i < nn;){
        if(j == m ){ OK = 0; break; }
        if(c[i].first == b[j].first ){ a[c[i].second] = b[j].second; i ++; j ++; }
        else if(c[i].first > b[j].first) j ++;
        else{ OK = 0;  break; }
    }
    if(OK){
        puts("YES");
        for(int i = 0; i < n; i ++) printf("%d ", a[i]); puts(""); return 0;
    }
    memset(a, -1, sizeof a);
    OK = 1;
    for(int i = 0, j = 0; i < nn;){
        if(j == m ){ OK = 0; break; }
        if(d[i].first == b[j].first ){ a[d[i].second] = b[j].second; i ++; j ++; }
        else if(d[i].first > b[j].first) j ++;
        else{ OK = 0;  break; }
    }
    if(OK){
        puts("YES");
        for(int i = 0; i < n; i ++) printf("%d ", a[i]); puts(""); return 0;
    }
    else puts("NO");
}