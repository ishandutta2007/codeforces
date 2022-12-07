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
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int q1,q2,q3,q4,m3,m4,l,r,c;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> q1 >> q2 >> q3 >> q4;
	for (int i=q1;i>=0;i--){
		l=0;
		r=min(q1-i,q2-1);
		while (l<r){
			c=(l+r+1)/2;
			m3=c+(i&&q2);
			if (m3>q3)r=c-1;else l=c;
		}
		m3=m4=l;
		if (i&&q2)m3++;
		if (i+l<q1&&q2)m4++;
		if (m3==q3&&m4==q4){
			for (int j=0;j<i;j++)putchar('4');
			if (q2)putchar('7');
			if (l&&q1-i-l>1){
				for (int j=0;j<q1-i-l;j++)putchar('4');
				putchar('7');
				for (int j=1;j<l;j++)putchar('4'),putchar('7');
			}else for (int j=0;j<l;j++)putchar('4'),putchar('7');
			for (int j=1;j<q2-l;j++)putchar('7');
			if (i+l<q1)putchar('4');
			return 0;
		}
	}
	puts("-1");
	return 0;
}