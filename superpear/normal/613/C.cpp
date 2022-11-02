#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143

int gcd(int a,int b)
{
	if (b==0) return a; else return gcd(b,a%b);
}

int N,flag,ec;
int a[105],b[105];


int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf("%d",&a[i]);
	int cc=a[1];
	for (int i=2;i<=N;i++) cc=gcd(cc,a[i]);
	for (int ans=cc;ans>=1;ans--)
		if (cc%ans==0)
		{
			flag=1;
			for (int i=1;i<=N;i++) b[i]=a[i]/ans;
			ec=0;
			for (int i=1;i<=N;i++)
				if (b[i]%2==1) ++ec;
			if (ec>1) continue;
			int ansk=ans;
			if (ec==0) ans*=2;
			printf("%d\n",ans);
			string S="";
			for (int i=1;i<=N;i++)
				if (b[i]%2==1) b[i]--,S+=char(i+96);
			for (int i=1;i<=N;i++)
				for (int j=1;j<=b[i]/2;j++)
					S=char(i+96)+S+char(i+96);
			for (int i=1;i<=ansk;i++)
				for (int j=0;j<S.size();j++)
					printf("%c",S[j]);
			printf("\n");
			return 0;
		}
	printf("0\n");
	for (int i=1;i<=N;i++)
		for (int j=1;j<=a[i];j++)
			printf("%c",char(i+96));
	printf("\n");
    return 0;
}