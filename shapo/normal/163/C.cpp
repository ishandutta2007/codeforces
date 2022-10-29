#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

#define maxn 500000

using namespace std;

struct event{double xx; int typ;};

int n, k, l, v1, v2, num = 0;
event sm[maxn];
double used[maxn], polosa;

bool cmp(const event &a, const event &b){return(a.xx < b.xx || a.xx == b.xx && a.typ > b.typ);}

int add_event(const int &x, int &num){
    if(double(x) < polosa){
        sm[num].xx = 0;
        sm[num].typ = 1;
        ++num;
        sm[num].xx = polosa - double(x);
        sm[num].typ = - 1;
        ++num;
        sm[num].xx = double(2 * l - x);
        sm[num].typ = 1;
        ++num;
        sm[num].xx = double(2 * l);
        sm[num].typ = -1;
        ++num;
    }
    else{
        sm[num].xx = double(2 * l - x);
        sm[num].typ = 1;
        ++num;
        sm[num].xx = sm[num - 1].xx + polosa;
        sm[num].typ = -1;
        ++num;
    }
    return 0;
}

int process_event(const int &x, double &leng, int &num){
    //printf("i = %d, xx = %.10lf, typ = %d\n", x, sm[x].xx, sm[x].typ);
    used[num] += sm[x].xx - leng;
    leng = sm[x].xx;
    num += sm[x].typ;
    return 0;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int cp = 0;

    scanf("%d%d%d%d", &n, &l, &v1, &v2);
    polosa = double(l) / double(v1 + v2) * double(v2);
    for(int i = 1; i <= n; ++i){
        int cur;
        scanf("%d", &cur);
        add_event(cur, num);
    }

    sort(sm, sm + num, cmp);
    double last = 0;
    for(int i = 0; i < num; ++i)process_event(i, last, cp);
    used[cp] += double(2 * l - last);

    for(int i = 0; i <= n; ++i){
        used[i] = used[i] / double(2 * l);
        printf("%.20lf\n", used[i]);
    }

    return 0;
}