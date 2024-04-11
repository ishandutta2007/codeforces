#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

int n;
char s[1005][20];

int main(){
	scanf("%d",&n);
	bool isok=0;
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		if(isok) continue;
		if(s[i][1]=='O'&&s[i][2]=='O'){
			s[i][1]=s[i][2]='+';
			isok=1;
			continue;
		}
		if(s[i][4]=='O'&&s[i][5]=='O'){
			s[i][4]=s[i][5]='+';
			isok=1;
			continue;
		}
	}
	if(isok) puts("YES"); else puts("NO");
	if(isok){
	for(int i=1;i<=n;i++) printf("%s\n",s[i]+1);
	}
	return 0;
	return 0;
}