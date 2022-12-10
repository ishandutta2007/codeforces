#include<set>
#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

int n,m,Q,x;
multiset<int> S[2],Le[2];
char s[3];

void Calc(int t)
{
	x=IN();
	int L=*--S[t].lower_bound(x),R=*S[t].upper_bound(x);
	Le[t].erase(Le[t].find(R-L));
	S[t].insert(x);
	Le[t].insert(x-L),Le[t].insert(R-x);
}

int main()
{
	n=IN(),m=IN(),Q=IN();
	S[0].insert(0),S[0].insert(n);
	S[1].insert(0),S[1].insert(m);
	Le[0].insert(n),Le[1].insert(m);
	while (Q--)
		scanf("%s",s),Calc(s[0]=='H'),printf("%I64d\n",1LL*(*--Le[0].end())*(*--Le[1].end()));
}