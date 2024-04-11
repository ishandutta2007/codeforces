#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int o = 20;
double mem[40][40][40];
double c, m, p, v;
int ic, im, ip, iv;

double cur(int dc, int dm, int dp) {
	if(mem[dc+o][dm+o][dp+o] != -1) {
		return mem[dc+o][dm+o][dp+o];
	}
	int i;
	double mul;
	double answer = 0;
	double a, b;
	if(2*ic+dc*iv > 2*iv) {
		answer += (c+dc*(v/2))*(cur(dc-2, dm+1, dp+1)+1);
	} else {
		a = m+dm*(v/2)+(c+dc*(v/2))/2;
		b = p+dp*(v/2)+(c+dc*(v/2))/2;
		mul = 1;
		for(i=2; 4*im+2*dm*iv+2*ic+dc*iv-4*(i-2)*iv>0; a-=v, b+=v, i++) {
			answer += (c+dc*(v/2))*i*b*mul;
			mul *= a;
		}
		answer += (c+dc*(v/2))*i*mul;
	}
	if(2*im+dm*iv > 2*iv) {
		answer += (m+dm*(v/2))*(cur(dc+1, dm-2, dp+1)+1);
	} else {
		a = c+dc*(v/2)+(m+dm*(v/2))/2;
		b = p+dp*(v/2)+(m+dm*(v/2))/2;
		mul = 1;
		for(i=2; 4*ic+2*dc*iv+2*im+dm*iv-4*(i-2)*iv>0; a-=v, b+=v, i++) {
			answer += (m+dm*(v/2))*i*b*mul;
			mul *= a;
		}
		answer += (m+dm*(v/2))*i*mul;
	}
	answer += p+dp*(v/2);
	mem[dc+o][dm+o][dp+o] = answer;
	return answer;
}

int main() {
	long long h, i, j, k;
	int t;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%lf %lf %lf %lf", &c, &m, &p, &v);
		ic = (int)round((10000*c));
		im = (int)round((10000*m));
		ip = (int)round((10000*p));
		iv = (int)round((10000*v));
		for(i=0; i<40; i++) {
			for(j=0; j<40; j++) {
				for(k=0; k<40; k++) {
					mem[i][j][k] = -1;
				}
			}
		}
		printf("%.10lf\n", cur(0, 0, 0));
	}
}