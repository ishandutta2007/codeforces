#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

char s[2000000];
int x;

struct summ{
	int x;
	int type;
};

summ a[2000];
int ver=0;

void parse(){
	int k=strlen(s);
	for (int i=0; i<k; i++){
		if (i==0){
			int zn=0;
			int tp=0;
			if (s[i]-'0'>=0&&s[i]-'0'<10){
				while (s[i]-'0'>=0&&s[i]-'0'<10)
					zn*=10, zn+=s[i]-'0', i++;
				i++;
				if (s[i]=='+') tp=1;
				i+=2;
			} else
			{
				zn=1;
				if (s[i]=='+') tp=1;
				i+=2;
			}
			ver++;
			a[ver].type=tp;
			a[ver].x=zn;
			continue;
		} else
		if (s[i]=='+'){
			int zn=0;
			int tp=0;
			i++;
			if (s[i]-'0'>=0&&s[i]-'0'<10){
				while (s[i]-'0'>=0&&s[i]-'0'<10)
					zn*=10, zn+=s[i]-'0', i++;
				i++;
				if (s[i]=='+') tp=1;
				i+=2;
			} else
			{
				zn=1;
				if (s[i]=='+') tp=1;
				i+=2;
			}
			ver++;
			a[ver].type=tp;
			a[ver].x=zn;
		} else
		if (s[i]=='-')
		{
			int zn=0;
			int tp=0;
			i++;
			if (s[i]!='a'&&s[i]!='+'){
				while (s[i]-'0'>=0&&s[i]-'0'<10)
					zn*=10, zn+=s[i]-'0', i++;
				i++;
				if (s[i]=='+') tp=1;
				i+=2;
			} else
			{
				zn=1;
				if (s[i]=='+') tp=1;
				i+=2;
			}
			ver++;
			a[ver].type=tp;
			a[ver].x=-zn;
		}
	}
}

vector <summ> plus;
vector <summ> minus;
vector <summ> nules;

int cmp(summ a, summ b){
	return a.x<b.x;
}

int do_oper(vector <summ> a,int st,int tp){
	int res=0;
	if (tp==1){
		for (int i=0; i<(int)a.size(); i++){
			if (a[i].type==0) res+=a[i].x*st, st++; else
				st++, res+=a[i].x*st;
		}
	} else
	{
		vector <summ> b=a;
		reverse(b.begin(),b.end());
		res=do_oper(b,st,1);
	}
	return res;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	scanf("%d\n",&x);
	gets(s);
	parse();

	//for (int i=1; i<=ver; i++)
	//	printf("%d %d\n",a[i].x,a[i].type);

	for (int i=1; i<=ver; i++)
		if (a[i].x>0) plus.push_back(a[i]); else
			if (a[i].x<0) minus.push_back(a[i]); else
				nules.push_back(a[i]);

	sort(plus.begin(),plus.end(),cmp);
	sort(minus.begin(),minus.end(),cmp);
	sort(nules.begin(),nules.end(),cmp);

	int aa=(int)plus.size();
	int bb=(int)minus.size();
	int cc=(int)nules.size();

	int mxres=-2000000000;

	mxres=max(mxres,do_oper(plus,x,0)+do_oper(minus,x+aa,0)+do_oper(nules,x+aa+bb,0));
	mxres=max(mxres,do_oper(plus,x,0)+do_oper(minus,x+aa,0)+do_oper(nules,x+aa+bb,1));
	mxres=max(mxres,do_oper(plus,x,0)+do_oper(minus,x+aa,1)+do_oper(nules,x+aa+bb,0));
	mxres=max(mxres,do_oper(plus,x,0)+do_oper(minus,x+aa,1)+do_oper(nules,x+aa+bb,1));
	mxres=max(mxres,do_oper(plus,x,1)+do_oper(minus,x+aa,0)+do_oper(nules,x+aa+bb,0));
	mxres=max(mxres,do_oper(plus,x,1)+do_oper(minus,x+aa,0)+do_oper(nules,x+aa+bb,1));
	mxres=max(mxres,do_oper(plus,x,1)+do_oper(minus,x+aa,1)+do_oper(nules,x+aa+bb,0));
	mxres=max(mxres,do_oper(plus,x,1)+do_oper(minus,x+aa,1)+do_oper(nules,x+aa+bb,1));
	
	mxres=max(mxres,do_oper(plus,x,0)+do_oper(minus,x+aa+cc,0)+do_oper(nules,x+aa,0));
	mxres=max(mxres,do_oper(plus,x,0)+do_oper(minus,x+aa+cc,0)+do_oper(nules,x+aa,1));
	mxres=max(mxres,do_oper(plus,x,0)+do_oper(minus,x+aa+cc,1)+do_oper(nules,x+aa,0));
	mxres=max(mxres,do_oper(plus,x,0)+do_oper(minus,x+aa+cc,1)+do_oper(nules,x+aa,1));
	mxres=max(mxres,do_oper(plus,x,1)+do_oper(minus,x+aa+cc,0)+do_oper(nules,x+aa,0));
	mxres=max(mxres,do_oper(plus,x,1)+do_oper(minus,x+aa+cc,0)+do_oper(nules,x+aa,1));
	mxres=max(mxres,do_oper(plus,x,1)+do_oper(minus,x+aa+cc,1)+do_oper(nules,x+aa,0));
	mxres=max(mxres,do_oper(plus,x,1)+do_oper(minus,x+aa+cc,1)+do_oper(nules,x+aa,1));

	mxres=max(mxres,do_oper(plus,x+bb,0)+do_oper(minus,x,0)+do_oper(nules,x+aa+bb,0));
	mxres=max(mxres,do_oper(plus,x+bb,0)+do_oper(minus,x,0)+do_oper(nules,x+aa+bb,1));
	mxres=max(mxres,do_oper(plus,x+bb,0)+do_oper(minus,x,1)+do_oper(nules,x+aa+bb,0));
	mxres=max(mxres,do_oper(plus,x+bb,0)+do_oper(minus,x,1)+do_oper(nules,x+aa+bb,1));
	mxres=max(mxres,do_oper(plus,x+bb,1)+do_oper(minus,x,0)+do_oper(nules,x+aa+bb,0));
	mxres=max(mxres,do_oper(plus,x+bb,1)+do_oper(minus,x,0)+do_oper(nules,x+aa+bb,1));
	mxres=max(mxres,do_oper(plus,x+bb,1)+do_oper(minus,x,1)+do_oper(nules,x+aa+bb,0));
	mxres=max(mxres,do_oper(plus,x+bb,1)+do_oper(minus,x,1)+do_oper(nules,x+aa+bb,1));

	mxres=max(mxres,do_oper(plus,x+cc+bb,0)+do_oper(minus,x,0)+do_oper(nules,x+bb,0));
	mxres=max(mxres,do_oper(plus,x+cc+bb,0)+do_oper(minus,x,0)+do_oper(nules,x+bb,1));
	mxres=max(mxres,do_oper(plus,x+cc+bb,0)+do_oper(minus,x,1)+do_oper(nules,x+bb,0));
	mxres=max(mxres,do_oper(plus,x+cc+bb,0)+do_oper(minus,x,1)+do_oper(nules,x+bb,1));
	mxres=max(mxres,do_oper(plus,x+cc+bb,1)+do_oper(minus,x,0)+do_oper(nules,x+bb,0));
	mxres=max(mxres,do_oper(plus,x+cc+bb,1)+do_oper(minus,x,0)+do_oper(nules,x+bb,1));
	mxres=max(mxres,do_oper(plus,x+cc+bb,1)+do_oper(minus,x,1)+do_oper(nules,x+bb,0));
	mxres=max(mxres,do_oper(plus,x+cc+bb,1)+do_oper(minus,x,1)+do_oper(nules,x+bb,1));

	mxres=max(mxres,do_oper(plus,x+cc,0)+do_oper(minus,x+aa+cc,0)+do_oper(nules,x,0));
	mxres=max(mxres,do_oper(plus,x+cc,0)+do_oper(minus,x+aa+cc,0)+do_oper(nules,x,1));
	mxres=max(mxres,do_oper(plus,x+cc,0)+do_oper(minus,x+aa+cc,1)+do_oper(nules,x,0));
	mxres=max(mxres,do_oper(plus,x+cc,0)+do_oper(minus,x+aa+cc,1)+do_oper(nules,x,1));
	mxres=max(mxres,do_oper(plus,x+cc,1)+do_oper(minus,x+aa+cc,0)+do_oper(nules,x,0));
	mxres=max(mxres,do_oper(plus,x+cc,1)+do_oper(minus,x+aa+cc,0)+do_oper(nules,x,1));
	mxres=max(mxres,do_oper(plus,x+cc,1)+do_oper(minus,x+aa+cc,1)+do_oper(nules,x,0));
	mxres=max(mxres,do_oper(plus,x+cc,1)+do_oper(minus,x+aa+cc,1)+do_oper(nules,x,1));

	mxres=max(mxres,do_oper(plus,x+bb+cc,0)+do_oper(minus,x+cc,0)+do_oper(nules,x,0));
	mxres=max(mxres,do_oper(plus,x+bb+cc,0)+do_oper(minus,x+cc,0)+do_oper(nules,x,1));
	mxres=max(mxres,do_oper(plus,x+bb+cc,0)+do_oper(minus,x+cc,1)+do_oper(nules,x,0));
	mxres=max(mxres,do_oper(plus,x+bb+cc,0)+do_oper(minus,x+cc,1)+do_oper(nules,x,1));
	mxres=max(mxres,do_oper(plus,x+bb+cc,1)+do_oper(minus,x+cc,0)+do_oper(nules,x,0));
	mxres=max(mxres,do_oper(plus,x+bb+cc,1)+do_oper(minus,x+cc,0)+do_oper(nules,x,1));
	mxres=max(mxres,do_oper(plus,x+bb+cc,1)+do_oper(minus,x+cc,1)+do_oper(nules,x,0));
	mxres=max(mxres,do_oper(plus,x+bb+cc,1)+do_oper(minus,x+cc,1)+do_oper(nules,x,1));

	cout<<mxres<<endl;

	return 0;
}