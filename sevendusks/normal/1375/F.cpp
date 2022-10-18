/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
pair<int,int> a[3];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
bool check(int a,int b,int c)
{
	static int sh[4];
	sh[0]=a;sh[1]=b;sh[2]=c;
	sort(sh,sh+3);
	if (sh[1]-sh[0]==sh[2]-sh[1]) return 0;
	return 1;
}
signed main()
{
	int a=read(),b=read(),c=read();
	printf("First\n");
	fflush(stdout);
	printf("10000000000\n");
	fflush(stdout);
	int x=read();
	if (x==1) a+=10000000000;
	if (x==2) b+=10000000000;
	if (x==3) c+=10000000000;
	int sh[3];sh[0]=a;sh[1]=b;sh[2]=c;
	sort(sh,sh+3);int v=2*sh[2]-sh[1]-sh[0];
	printf("%lld\n",v);
	fflush(stdout);
	x=read();
	if (x==1) a+=v;
	if (x==2) b+=v;
	if (x==3) c+=v;
	sh[0]=a;sh[1]=b;sh[2]=c;sort(sh,sh+3);
	assert(sh[1]-sh[0]==sh[2]-sh[1]);
	printf("%lld\n",sh[1]-sh[0]);
	fflush(stdout);
	assert(read()==0);
}