#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n,ans[2000222],q[2000222],f[2000111], zer = 0;
char a[2000222];

void mul(int x){
	if (x == 10){
		zer ++;
		return;
	}
	ans[0] ++;
	for (int i=1;i<=ans[0];i++)ans[i] *= x;
	for (int i=1;i<=ans[0];i++) {
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	while (ans[0] > 1 && ans[ans[0]] == 0)ans[0]--;
}

void div(int x){

	int s = 0;
	for (int i=ans[0]; i>0; i--) {
		s *= 10;
		s += ans[i];
		ans[i] = s / x;
		s %= x;
	}
	while (ans[0] > 1 && ans[ans[0]] == 0)ans[0]--;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	n = strlen(a);
	ans[0] = 1;
	ans[1] = 1;
	for (int i=0;i<n;i++) {
		if (a[i] == '?'){
			if (i==0)mul(9);else mul(10);
		}else{
			if (a[i] >= 'A' && a[i] <= 'Z'){
				q[a[i]-'A'] = 1;
				if (i==0)f[a[i]-'A']= 1;
			}
		}
	}
	int kol = 0, fi = 0;
	for (int i=0;i<26;i++) {
		if (q[i]) kol ++;
		if (f[i]) fi = 1;
	}
	if (!fi) {
		for (int i=0;i<kol;i++)mul(10-i);
	}else{	
		mul(9);
		for (int i=0;i<kol - 1; i++)mul(9-i);
	}
	for (int i=ans[0];i>0;i--)putchar('0'+ans[i]);
	for (int i=0;i<zer;i++)putchar('0');
	puts("");
	return 0;
}