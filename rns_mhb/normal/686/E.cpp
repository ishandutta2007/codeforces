#include <bits/stdc++.h>
using namespace std;

#define INF ((1LL<<62) - 1 << 1) + 1

typedef long long LL;
int T, n;
LL a, b, c, lim[5][3];
bool flag;

struct Point{
	LL x;
	LL y;
	LL z;
}OP, P;

LL low(LL x) {
    if(x % 2 == 0)	return x / 2;
    return (x - 1) / 2;
}

bool test(LL rr) {
    LL a[6], le[6], ri[6], k;
    for (LL l = 0; l < 2; l ++) {
        flag = 0;
        for(int i = 0; i < 4; i ++) {
            le[i] = low(lim[i][1] - l - rr + 1);
            ri[i] = low(lim[i][0] - l + rr);
            if(le[i] > ri[i]) flag = 1;
        }
        le[0] -= l;
        ri[0] -= l;
        if(flag) continue;
        flag = 0;
        if(le[1] + le[2] + le[3] > ri[0]) flag = 1;
        if(ri[1] + ri[2] + ri[3] < le[0]) flag = 1;
        if(!flag) {
            if(le[1] + le[2] + le[3] <= le[0]) {
                k = 0;
                for(int i = 1; i < 4; i ++) {
                    a[i] = le[i];
                    k += a[i];
                }
                for(int i = 1; i < 4; i ++) {
                    if(k - a[i] + ri[i] >= le[0]) {
                        a[i] += le[0] - k;
                        break;
                    }
                    else {
                        k = k - a[i] + ri[i];
                        a[i] = ri[i];
                    }
                }
                OP.x = a[2] + a[3] + l, OP.y = a[1] + a[3] + l, OP.z = a[1] + a[2] + l;
            }
            else {
                OP.x = le[2] + le[3] + l, OP.y = le[1] + le[3] + l, OP.z = le[1] + le[2] + l;
            }
            return 1;
        }
    }
    return 0;
}

LL calc(LL le, LL ri){
	if(le == ri)	return le;
	LL mid = le + (ri - le) / 2;
	if(!test(mid))	return calc(mid + 1, ri);
	else	return calc(le, mid);
}


int main(){
	//freopen("sample.in", "r", stdin);
	//freopen("par.out", "w", stdout);
	scanf("%d", &T);
	while(T --){
		for(int i = 0; i < 4; i ++){
			lim[i][0] = INF;
			lim[i][1] = - INF;
		}
		scanf("%d", &n);
		while(n --){
			scanf("%I64d %I64d %I64d", &a, &b, &c);
			if(lim[0][0] > a + b + c)	lim[0][0] = a + b + c;
			if(lim[0][1] < a + b + c)	lim[0][1] = a + b + c;
			if(lim[1][0] > - a + b + c)	lim[1][0] = - a + b + c;
			if(lim[1][1] < - a + b + c)	lim[1][1] = - a + b + c;
			if(lim[2][0] > a - b + c)	lim[2][0] = a - b + c;
			if(lim[2][1] < a - b + c)	lim[2][1] = a - b + c;
			if(lim[3][0] > a + b - c)	lim[3][0] = a + b - c;
			if(lim[3][1] < a + b - c)	lim[3][1] = a + b - c;
		}
		test(calc(0, 3000000000000000005));
		printf("%I64d %I64d %I64d\n", OP.x, OP.y, OP.z);
	}
}