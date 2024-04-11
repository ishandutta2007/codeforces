#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define N 1111111

int b, c;
int p[N], q[N], cnt;
int x[N], fi[N];
int n[N];
int B[N];
char bb[N], nn[N], nnn[N];
char ss[N];

int pow(int a, int b, int mod){
    if(!b) return 1 % mod;
    int r = pow(a, b / 2, mod);
    r = 1ll * r * r % mod;
    if(b & 1) return 1ll * r * a % mod;
    return r;
}

void get_prime(int c){
    int cc = sqrt(c);
    for(int i = 2; i <= cc; i ++) if(c % i == 0) {
        p[cnt] = i;
        int r = 1;
        while(c % i == 0) q[cnt] ++, c /= i, r *= i;
        x[cnt] = r;
        fi[cnt] = r - (r / i);
        cnt ++;
    }
    if(c > 1) p[cnt] = c, q[cnt] = 1, x[cnt] = c, fi[cnt ++] = c - 1;
}

int gcd(int a, int b) {return (!b) ? a : gcd(b, a % b);}

int extEuclid(int a, int b, int &x, int &y) {
	if (!b) {
		x=1, y=0;
		return a;
	}
	int d, tmp;
	d = extEuclid(b, a%b, x, y);
	tmp = x, x = y, y = tmp - (a / b) * y;
	return d;
}


int modular_linear_equation(int a, int b, int n) {
    a = (a % n + n) % n;
    b = (b % n + n) % n;
	int x, y;
	int g = extEuclid(a, n, x, y);
	return (1ll * x * b % n + n) % n;
}

int chinese_remainder2(int r[], int w[], int len) {
	int ret = r[0], ww = w[0];
	for (int i = 1; i < len; i ++)	{
        if((r[i] - ret) % w[i] == 0) {ww *= w[i]; continue;}
		int x = modular_linear_equation(ww, r[i] - ret, w[i]);
		ret = x * ww + ret;
		ww *= w[i];
	}
	return (ww + ret % ww) % ww;
}

int f(char *nn){
    int len = strlen(nn);
    for(int i = 0; i < cnt; i ++){
        int len1 = 0;
        int qq = q[i];
        while(qq) ss[len1 ++] = qq % 10 + '0', qq /= 10;
        reverse(ss, ss + len1);
        ss[len1]  = NULL;

        n[i] = 0;
        if(b % p[i] == 0){
            if(len > len1) {B[i] = 0; continue;}
            if(len == len1 && strcmp(nn, ss) >= 0) {B[i] = 0; continue;}
            for(int j = 0; j < len; j ++){
                n[i] = n[i] * 10 + nn[j] - '0';
            }
            B[i] = pow(b, n[i], x[i]);
            continue;
        }

        for(int j = 0; j < len; j ++){
            n[i] = 1ll * n[i] * 10 % fi[i];
            n[i] = (n[i] + nn[j] - '0') % fi[i];
        }
        B[i] = pow(b, n[i], x[i]);
    }

    int ans = chinese_remainder2(B, x, cnt);
    ans %= c;
    return ans;
}

int main(){
    //freopen("d.in", "r", stdin);
    scanf("%s %s %d", bb, nn, &c);

    int len = strlen(bb);
    b = 0;
    for(int i = 0; i < len; i ++){
        b = 1ll * b * 10 % c;
        b = (b + bb[i] - '0') % c;
    }

    get_prime(c);

    len = strlen(nn);
    strcpy(nnn, nn);
    for(int j = len - 1; j >= 0; j --){
        if(nnn[j] != '0') {nnn[j] -= 1; break;}
        nnn[j] = '9';
    }

    int ans = (f(nn) - f(nnn) + c) % c;
    if(ans <= 0) ans += c;
    printf("%d\n", ans);
}