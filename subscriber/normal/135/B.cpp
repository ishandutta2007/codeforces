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
#define sqr(x) ((x)*1ll*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;

int x[11],y[11];

long long R(pair<int,int>a,pair<int,int>b){
	return sqr(a.F-b.F)+sqr(a.S-b.S);
}

bool o1(vector<pair<int,int> >a){
	if (a.size()!=4)return 0;
	sort(a.begin(),a.end());
	for (int i=0;i<24;i++){
		long long l1=R(a[0],a[1]);
		long long l2=R(a[1],a[2]);
		long long l3=R(a[2],a[3]);
		long long l4=R(a[3],a[0]);
		long long l5=R(a[0],a[2]);
		long long l6=R(a[1],a[3]);
		if (l1==l2&&l2==l3&&l3==l4&&l5==l6)return 1;
		next_permutation(a.begin(),a.end());
	}
	return 0;
}

bool o2(vector<pair<int,int> >a){
	if (a.size()!=4)return 0;
	sort(a.begin(),a.end());
	for (int i=0;i<24;i++){
		long long l1=R(a[0],a[1]);
		long long l2=R(a[1],a[2]);
		long long l3=R(a[2],a[3]);
		long long l4=R(a[3],a[0]);
		long long l5=R(a[0],a[2]);
		long long l6=R(a[1],a[3]);
		if (l1==l3&&l2==l4&&l5==l6)return 1;
		next_permutation(a.begin(),a.end());
	}
	return 0;
}


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	for (int i=0;i<8;i++)cin >> x[i] >> y[i];
	for (int o=0;o<pw(8);o++){
		vector<pair<int,int> >v1,v2;
		for (int i=0;i<8;i++)if (o&pw(i))v1.pb(mp(x[i],y[i]));else v2.pb(mp(x[i],y[i]));
		if (o1(v1)&&o2(v2)){
			puts("YES");
			for (int i=0;i<8;i++)if (o&pw(i))cout << i+1 << " ";
			puts("");
			for (int i=0;i<8;i++)if ((o&pw(i))==0)cout << i+1 << " ";
			puts("");
			return 0;
		}
	}
	puts("NO");
	return 0;
}