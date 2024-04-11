#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<sstream>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;
typedef vector<string> Vs;

string s,t,c,res,s1,s2,s3;
int num[10];

void Work(string c){
	For(i,0,s.length()) num[s[i]-'0']++;
	For(i,0,c.length()) num[c[i]-'0']--;
	For(i,0,t.length()) num[t[i]-'0']--;
	res+=char(127);
	if (t[0]!='0'){
		s1=t;
		For(i,0,10) For(j,0,num[i]) s1+=char(i+'0');
		res=s1;
	}
	int x=-1;
	For(i,1,10) if (num[i]) {x=i;break;}
	if (~x){
		s2=s3=char(x+'0');
		num[x]--;
		For(i,0,t[0]-'0') For(j,0,num[i]) s2+=char(i+'0');
		For(i,0,t[0]-'0'+1) For(j,0,num[i]) s3+=char(i+'0');
		s2+=t;
		s3+=t;
		For(i,t[0]-'0',10) For(j,0,num[i]) s2+=char(i+'0');
		For(i,t[0]-'0'+1,10) For(j,0,num[i]) s3+=char(i+'0');
		res=min(res,s2);
		res=min(res,s3);
	}
	cout<<res<<endl;
}

int main(){
	cin>>s>>t;
	sort(s.begin(),s.end());
	if (s=="01"){
		puts("0");
		return 0;
	}
	For(i,1,10){
		int tmp=int(s.length())-i;
		stringstream ss;
		ss<<tmp;ss>>c;
		if (c.length()==i){
			Work(c);
			return 0;
		}
	}
}