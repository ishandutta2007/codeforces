#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dque[MAXN];
int s=0,t=0,num=0,q,maxi;
double mean=0;
int main()
{
	memset(dque,0,sizeof(dque));
	scanf("%d",&q);
	while(q--)
	{
		int type,x;
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d",&x);
			if(num!=0) {mean=(mean*num+x-maxi)/num; dque[t++]=maxi;} else {mean=x; num++;}
			maxi=x;
			while(s<t&&dque[s]<mean)
			{
				mean=(mean*num+dque[s])/(num+1);
				num++;
				s++;
			}
		}
		else
			printf("%.10f\n",(double)maxi-mean);
	}
	return 0;
}