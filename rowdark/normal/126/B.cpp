#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair
#define P1 1000000007
#define P2 31

long long P[1000001];
long long H[1000001],f1,HH;
long l,r,mid,i,j,len;
char S[1000100];

inline long long gethash(long L,long R){
	f1=H[R]-H[L]*P[R-L];
	if(P1<=f1||f1<=-P1) f1%=P1;
	if(f1<0) f1+=P1;
	return f1;
}

inline bool check2(){
	for(i=1;i+mid<len;++i)
		if(gethash(i,i+mid)==HH)
			return 1;
	return 0;
}

int main(){
	for(P[0]=1,i=1;i<=1000000;++i) if(P1<=(P[i]=P[i-1]*P2))P[i]%=P1;
	scanf("%s",S+1);
	len=strlen(S+1);
	for(i=1;i<=len;++i) if(P1<=(H[i]=H[i-1]*P2+S[i])) H[i]%=P1;
	l=0,r=len;
	while(mid=(l+r)>>1,l+1!=r){
		HH=H[mid];
		if(check2())
			l=mid;
		else
			r=mid;
		}
	for(;l;--l) if(gethash(len-l,len)==H[l]) break;
	if(l==0) printf("Just a legend\n");
	else S[l+1]=0,printf("%s\n",S+1);
	scanf("%s",S+1);
	return 0;
}