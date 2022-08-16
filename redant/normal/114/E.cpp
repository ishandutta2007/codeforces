#include <cstdio>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

#define MX 300000010

//bitset<MX> isNotPrime;
//vector<bool> isNotPrime(MX);
vector<bool> isP(MX,true);

void pre()
{
	int sqri = (int)sqrt(MX);
	for(int i=3;i<sqri;i+=2) 
		//if(!isNotPrime[i])
		if(isP[i])
	{
		//printf("%d\n",i);
		for(int j=i*i,k=i+i;j<MX;j+=k)
			//isNotPrime[j] = true;
			isP[j] = false;
	}
}

int main()
{
	pre();
	int l, h, ans = 0;
	scanf("%d %d",&l,&h);
	if(l<=2 && 2<=h) ans = 1;
	l=max(l,5);
	l+=(l%4)^1;
	for(int i=l;i<=h;i+=4) 
			//if(!isNotPrime[i]) ans++;
			if(isP[i]) ans++;
	printf("%d\n",ans);
	return 0;
}