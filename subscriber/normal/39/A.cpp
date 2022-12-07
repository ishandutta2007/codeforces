#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct T{int x,e;} q[1111];

bool my(T A,T B){
	return A.x<B.x;
}

string s;
int a,i,o=0,ans=0;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> a;
	cin >> s;
	i=0;
	while (i<s.length()){
		int p=1;
		int ii=2;
		int x=0;
		int f=0;
		if ((s[i]=='+'&&s[i+1]!='+')||(s[i]=='+'&&s[i+1]=='+'&&s[i+2]=='+'))i++;
		else if (s[i]=='-'){
			p=-1;
			i++;			
		}
		while(s[i]>='0'&&s[i]<='9'){
			f=1;
			x=x*10+s[i]-'0';
			i++;			
		
		}
		if (s[i]=='*')i++;
		if (!f)x=1;
		x*=p;
		if (s[i]=='+'){
			ii=1;
			i+=2;
		}
		while (i<s.length()&&s[i]!='+'&&s[i]!='-')i++;
		if (ii==2)i+=2;
		q[o].x=x;
		q[o++].e=ii;
	}
	sort(q,q+o,&my);
	for (int i=0;i<o;i++){
		if (q[i].e==1)a++;
		ans+=a*q[i].x;
		if (q[i].e==2)a++;

	}
	cout << ans << endl;
	return 0;
}