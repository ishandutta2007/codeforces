#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
using namespace std;

struct Sol
{
	int s[4];
	Sol(int a,int b,int c,int d) {s[0]=a,s[1]=b,s[2]=c,s[3]=d;}
};vector<Sol> S;
vector<int> V;
typedef vector<int>::iterator It;
int v[10],u[10],C[256],B[256],Time,n,Len,tmp,need,x;
char s[100],t[100];

void Check(int a,int b,int c,int d)
{
	if (d>255) return;
	sprintf(t,"%s%d",s,d);Len=strlen(t);
	For(i,0,Len/2+1) if (t[i]!=t[Len-i-1]) return;
	S.Pb(Sol(a,b,c,d));
}

int main()
{
	scanf("%d",&n);
	For(i,0,n) scanf("%d",&x),v[x]=1,need|=1<<x;
	if (n>6) return puts("0"),0;
	For(i,0,256)
	{
		sprintf(s,"%d",i);int f=1,b=0;
		For(j,0,strlen(s)) {if (!v[s[j]-'0']) f=0;b|=1<<s[j]-'0';}
		if (f) V.Pb(i),C[i]=1,B[i]=b;
	}
	for (It a=V.begin();a!=V.end();a++)
		for (It b=V.begin();b!=V.end();b++)
			for (It c=V.begin();c!=V.end();c++)
				if ((B[*a]|B[*b]|B[*c])==need)
				{
					sprintf(s,"%d%d%d",*a,*b,*c);
					Check(*a,*b,*c,s[0]-'0');
					if (s[1]!='0') Check(*a,*b,*c,(s[1]-'0')*10+(s[0]-'0'));
					if (s[2]!='0') Check(*a,*b,*c,(s[2]-'0')*100+(s[1]-'0')*10+(s[0]-'0'));
				}
	printf("%d\n",S.size());
	for (vector<Sol>::iterator i=S.begin();i!=S.end();i++,puts(""))
	{
		printf("%d",i->s[0]);
		For(j,1,4) printf(".%d",i->s[j]);
	}
}