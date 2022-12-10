#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<string>
#include<bitset>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';
	return !f?x:-x;
}

string s,t;
int n,m,tmp,n2,m2,x2,y2,xx,yy,ans;
Vi S,T;

int cal(int n,int m,int x,int y){
	if (n>0&&m>0&&x==y){
		if (n<m) n++;else m++;
	}
	return max(n,m)-1;
}

int main(){
	cin>>s>>t;
	For(i,0,s.length()) if (i==0||s[i]!=s[i-1]) n++;
	For(i,0,t.length()) if (i==0||t[i]!=t[i-1]) m++;
	ans=cal(n,m,s[0]=='a',t[0]=='a');
	xx=0;yy=0;
	n2=0;m2=0;
	For(i,0,s.length()+1) if (i==0||i==s.length()||s[i]!=s[i-1]){
		m2=0;
		For(j,0,t.length()+1) if (j==0||j==t.length()||t[j]!=t[j-1]){
			//swap(s[0..i-1],t[0..j-1])
			int n3=n-n2+m2-(i<s.length()&&j>0&&t[j-1]==s[i]);
			int m3=m-m2+n2-(j<t.length()&&i>0&&s[i-1]==t[j]);
			int x3=(j>0?t[0]=='a':i<s.length()?s[i]=='a':0);
			int y3=(i>0?s[0]=='a':j<t.length()?t[j]=='a':0);
			int tmp=1+cal(n3,m3,x3,y3);
			if (tmp<ans){
				ans=tmp;
				xx=i;yy=j;
			}
			m2++;
		}
		if (++n2>3) break;
	}
	n2=0;m2=0;
	For(j,0,t.length()+1) if (j==0||j==t.length()||t[j]!=t[j-1]){
		n2=0;
		For(i,0,s.length()+1) if (i==0||i==s.length()||s[i]!=s[i-1]){
			//swap(s[0..i-1],t[0..j-1])
			int n3=n-n2+m2-(i<s.length()&&j>0&&t[j-1]==s[i]);
			int m3=m-m2+n2-(j<t.length()&&i>0&&s[i-1]==t[j]);
			int x3=(j>0?t[0]=='a':i<s.length()?s[i]=='a':0);
			int y3=(i>0?s[0]=='a':j<t.length()?t[j]=='a':0);
			int tmp=1+cal(n3,m3,x3,y3);
			if (tmp<ans){
				ans=tmp;
				xx=i;yy=j;
			}
			n2++;
		}
		if (++m2>3) break;
	}
	int d=0;
	printf("%d\n",ans);
	if (xx||yy){
		string ss=t.substr(0,yy)+s.substr(xx,s.length());
		string tt=s.substr(0,xx)+t.substr(yy,t.length());
		s=ss;
		t=tt;
		printf("%d %d\n",xx,yy);
//		d+=yy-xx;
	}
	For(i,1,s.length()) if (s[i]!=s[i-1]) S.pb(i);
	For(i,1,t.length()) if (t[i]!=t[i-1]) T.pb(i);
	if (s.size()&&t.size()&&s[0]==t[0]){
		if (S.size()<T.size()) S.pb(0);else T.pb(0);
	}
	sort(S.begin(),S.end());
	sort(T.begin(),T.end());
//	For(i,0,S.size()) printf("%d ",S[i]);puts("");
//	For(i,0,T.size()) printf("%d ",T[i]);puts("");
	int i=0,j=0;
	while (i<S.size()||j<T.size()){
		int x=(i==S.size()?s.length():S[i]);
		int y=(j==T.size()?t.length():T[j]);
		printf("%d %d\n",x+d,y-d);
		d+=(y-d)-(x+d);
		if (i<S.size()) i++;
		if (j<T.size()) j++;
	}
}