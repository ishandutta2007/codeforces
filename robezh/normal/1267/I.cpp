#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 5;

int n;
int ban[maxn];

int better(int x, int y) {
    printf("? %d %d\n",x,y); fflush(stdout);

    char res; scanf(" %c",&res);
    if(res == '>') return 1;
    return 0;
}

int getBest() {
    int best = 0;
    for(int x=1;x<=2*n;x++) {
        if(ban[x]) continue;
        if(!best || better(x, best)) {
            best = x;
        }
    }
    return best;
}

int getThreeBest() {
    vector<int> vec;
    for(int x=1;x<=2*n;x++) {
        if(ban[x]) continue;
        vec.push_back(x);
    }
    int sz = vec.size();

    int a = vec[0], b = vec[1], c = vec[2];
    if(better(b,a)) swap(a,b);

    for(int i=3;i<sz;i++) {
        int d = vec[i];
        if(better(d,c)) swap(c,d);

        if(better(d,b)) {
            int ta = c;
            int tb = d;
            int tc = a;
            a = ta;
            b = tb;
            c = tc;
        }
    }
    ban[a] = ban[b] = ban[c] = 1;
    //printf("Three: %d %d %d\n",a,b,c);
}

void solve(int tnum) {
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++) ban[i] = 0;
    getThreeBest();
    int m = n - 3;
    while(m > 0) {
        int best = getBest();
        //printf("Best: %d\n",best);
        ban[best] = 1;
        m--;
    }
    printf("!\n"); fflush(stdout);
}

int main() {
    int tnum; scanf("%d",&tnum);
    for(int i=1;i<=tnum;i++) solve(i);
}